
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

//TODO: Put here a special singleton "SPK" module ?

juce::StringArray listAllInputDevices();
juce::StringArray listAllOutputDevices();
//void listenToDevice(const std::string& s);

//TODO: I'll nee an associative container for all input & output midi devices mentionned in the configuration !

// ? DeviceHub ...

class MIC : public juce::MidiInputCallback
{
public:
	void handleIncomingMidiMessage(juce::MidiInput* source, const juce::MidiMessage& message) override;
private:
};

struct Device
{
	int index;
	std::string name;
	std::string configurationFile;
	MIC* mic;

	Device(int i, const std::string& n, const std::string& cf, MIC* m) : index(i), name(n), configurationFile(cf), mic(m) {}
	Device() {} // Needed for the vector<DEvice>
};

#endif // AUDIO_DEVICES
