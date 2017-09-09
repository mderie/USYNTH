
#include "AudioDevices.hpp"
#include "CommonStuffs.hpp"

void BasicSynth::getNextAudioBlock(const AudioSourceChannelInfo &bufferToFill)
{
  ToneGeneratorAudioSource::getNextAudioBlock(bufferToFill);
  // Extra process can take place here
}

//TODO: Iterate through all midi input devices and log their names if needed !
