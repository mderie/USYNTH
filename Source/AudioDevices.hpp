
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

//TODO: I'll nee an associative container for all input & output midi devices mentionned in the configuration !

class GlobalMidiInputCallback : public juce::MidiInputCallback
{
public:
	void handleIncomingMidiMessage(juce::MidiInput* source, const juce::MidiMessage& message) override;
private:
};

#endif // AUDIO_DEVICES
