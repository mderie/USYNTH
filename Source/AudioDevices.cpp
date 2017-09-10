
#include "AudioDevices.hpp"
#include "CommonStuffs.hpp"

#include <iostream>

juce::StringArray listAllInputDevices()
{
	std::cout << "listAllInputDevices 1" << std::endl;
  juce::StringArray result = juce::MidiInput::getDevices(); // BOUM !!!
  std::cout << "listAllInputDevices 2" << std::endl;
  std::string found = "Found audio input device = ...";

	for (auto item : result)
	{
		std::cout << "listAllInputDevices 3" << std::endl;
		logThis(found.c_str(), Target::device);
		logThis(item.toUTF8(), Target::device);
	}
	std::cout << "listAllInputDevices 4" << std::endl;
	return result;
}

juce::StringArray listAllOutputDevices()
{
  juce::StringArray result = juce::MidiOutput::getDevices();
  std::string found = "Found audio output device = ...";

	for (auto item : result)
	{
		logThis(found.c_str(), Target::device);
		logThis(item.toUTF8(), Target::device);
	}
	return result;
}

void BasicSynth::getNextAudioBlock(const AudioSourceChannelInfo &bufferToFill)
{
  ToneGeneratorAudioSource::getNextAudioBlock(bufferToFill);
  // Extra process can take place here
}

//TODO: Iterate through all midi input devices and log their names if needed !
