
#ifndef AUDIO_DEVICES
#define AUDIO_DEVICES

// Don't do this...
//#include "juce_audio_basics/sources/juce_ToneGeneratorAudioSource.h"

// Do this:)
#include "../JuceLibraryCode/JuceHeader.h"

class BasicSynth : public juce::ToneGeneratorAudioSource
{
public:
  void getNextAudioBlock(const AudioSourceChannelInfo &bufferToFill) override;
};

//TODO: Put here a special singleton "OUT" module ?

//TODO: Iterate and log eventually the audio input devices seen by JUCE !

#endif // AUDIO_DEVICES
