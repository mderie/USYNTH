
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

juce::StringArray listAllInputDevices();
juce::StringArray listAllOutputDevices();
//void listenToDevice(const std::string& s);

#endif // AUDIO_DEVICES
