
#ifndef AUDIO_MODULES
#define AUDIO_MODULES

#include <string>
#include <map>

// VCO, VCF, VCA & LFO are already a good start ! All are AC based !
// Add envelopes here ? DC based
// Add Random here ?
// Add AND operation here ?
// Does the OR operation as simple as a mixer ?
// Where to put the n-duplicator ?
// Where to put the clock diviser ?

// Base class for all modules and cables (and other stuff ?)
class CaseElement
{
public:
  const std::string& GetName();
};

typedef std::map<std::string, std::string> dico;
const int MAX_LOOP = 10;

// Base class for all audio modules...
class AudioModule : public CaseElement
{
protected:
  dico m_ins;
  dico m_outs;
  int m_max_loop; // Avoid infinite recursion if the cable patch path holds one or more loops
public:
  AudioModule();
//TODO: Check if others need to access ins & outs...
};

class WhiteNoise : public AudioModule
{
public:
  WhiteNoise();
  ~WhiteNoise();
};

// Homage to Plancton ! Should probably inherit from PatchCable ?
class NinjaStar : public AudioModule
{
public:
  NinjaStar();
  ~NinjaStar();
};

class PatchCable : public CaseElement
{
};

#endif // AUDIO_MODULES
