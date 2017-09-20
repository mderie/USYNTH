
#ifndef THREADED_TIMERS
#define THREADED_TIMERS

#include "../JuceLibraryCode/JuceHeader.h"

class BPMTimer : public juce::HighResolutionTimer
{
private:
//TODO
public:
	void hiResTimerCallback() override;
};

#endif // THREADED_TIMERS
