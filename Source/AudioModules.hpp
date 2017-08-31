
#ifndef AUDIO_MODULES
#define AUDIO_MODULES

#include <string>
#include <vector>
#include <map>

#include "CommonStuffs.hpp"

// VCO, VCF, VCA & LFO are already a good start ! All are AC based !
// Add envelopes here ? DC based
// Does the OR operation as simple as a mixer ?
// Where to put the n-duplicator ?
// Where to put the clock diviser ?

#ifdef WIN32
#undef OUT
#endif

// Don't use LAST_ITEM, it is a trick :)
enum class Kind { CBL, LFO, VCO, VCF, VCA, RND, DUP, ENV, ADD, SUB, AND, MIX, NOT, PAN, OUT, LAST_ITEM }; // With the NOT maybe we don't need the SUB ?
const std::string Kinds[(int) Kind::LAST_ITEM] = { "CBL", "LFO", "VCO", "VCF", "VCA", "RND", "DUP", "ENV", "ADD", "SUB", "AND", "MIX", "NOT", "PAN", "OUT" };

// class Knob ?

// Base class for all elements in a case (cable and module)
class CaseElement : public IAmDumpable
{
protected:
  Kind m_kind;
  std::string m_id;
public:
  const std::string& getId() { return m_id; } // Something like "VCO_1"
  Kind getKind() { return m_kind; } // Something like Kind::VCO
  std::string dump() override;
};

// The case sole instance
class CaseSingleton : public IAmDumpable
{
private:
  std::map<std::string, CaseElement*> m_elements; // Tuple <element.id, element*>
  // We can't be instatied :)
  CaseSingleton() {}
  CaseSingleton(const CaseSingleton&) {}
  static CaseSingleton* s_instance;
public:
/*
  CaseSingleton();
  ~CaseSingleton();
*/

	static CaseSingleton* getInstance();
  void add(CaseElement* element);
  void del(CaseElement* element);
  CaseElement* getElement(const std::string& id);
  int getSize();
  //const std::string& getID(int index);
  // Implement a getFirst, getNext by kind ?
  void clear(); // All this to not published the private collection
  std::string dump() override;
};

typedef std::map<std::string, std::string> Dico;
typedef std::map<std::string, std::string>::const_iterator DicocIt;
const int LOOP_COUNTER_MAX = 10;

// Base class for all audio modules...
class AudioModule : public CaseElement
{
protected:
  Dico m_ins;
  Dico m_outs;
  int m_loop_counter_max; // Avoid infinite recursion if the cable patchs path holds one or more loops
  int m_loop_counter;
public:
  AudioModule();
  void reset();
  std::string dump() override;
  //TODO: Check if others need to access ins & outs...
};

class WhiteNoise : public AudioModule
{
public:
  WhiteNoise();
  ~WhiteNoise();
};

// Homage to Plancton ! could also inherit from PatchCable ?
class NinjaStar : public AudioModule
{
public:
  NinjaStar();
  ~NinjaStar();
};

class PatchCable : public CaseElement
{
public:
  PatchCable();
  ~PatchCable();
};

#endif // AUDIO_MODULES
