
#include "AudioDevices.hpp"
#include "CommonStuffs.hpp"

#include <iostream>

void MIC::handleIncomingMidiMessage(juce::MidiInput* source, const juce::MidiMessage& message)
{
	logThis("Incomming message = ...", Target::midi);
	const juce::uint8* p = message.getRawData();
	std::string s;
	for (int i = 0; i < message.getRawDataSize(); i++)
	{
		s = intToStr(static_cast<int>(*(p + i)));
		logThis(s.c_str(), Target::midi);
	}
}

std::vector<Device> inDevices;
std::vector<Device> outDevices;

//LPCallback lpcb;
//midiInput = juce::MidiInput::openDevice(lpInIndex, &lpcb);
//midiInput->start();

juce::StringArray listAllInputDevices()
{
	//std::cout << "listAllInputDevices 1" << std::endl;
  juce::StringArray result = juce::MidiInput::getDevices(); // No BOUM anymore... Added a #define in the AppConfig.H !!!
  inDevices.resize(result.size());
  //std::cout << "listAllInputDevices 2" << std::endl;
  //std::string found = "Found audio input device = ...";

	//for (auto item : result)
	for (int i = 0; i < result.size(); i++)
	{
		//std::cout << "listAllInputDevices 3" << std::endl;
		//logThis(found.c_str(), Target::device);
		//logThis(item.toUTF8(), Target::device);
		inDevices.push_back(Device(i, result[i].toStdString(), "", nullptr));
	}
	//std::cout << "listAllInputDevices 4" << std::endl;
	return result;
}

juce::StringArray listAllOutputDevices()
{
	std::cout << "listAllOutputDevices 1" << std::endl;
  juce::StringArray result = juce::MidiOutput::getDevices();
  std::cout << "listAllOutputDevices 2" << std::endl;
  std::string found = "Found audio output device = ...";

	for (auto item : result)
	{
		std::cout << "listAllOutputDevices 3" << std::endl;
		logThis(found.c_str(), Target::device);
		logThis(item.toUTF8(), Target::device);
	}
	std::cout << "listAllOutputDevices 4" << std::endl;
	return result;
}

void BasicSynth::getNextAudioBlock(const AudioSourceChannelInfo &bufferToFill)
{
  ToneGeneratorAudioSource::getNextAudioBlock(bufferToFill);
  // Extra process can take place here
}

//midiLP = juce::MidiOutput::openDevice(lpOutIndex);
