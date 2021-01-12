#ifndef SDDS_TIMEDEVENTS_H
#define SDDS_TIMEDEVENTS_H

#include <iostream>
#include <chrono>
#include <string>

namespace sdds{
    const int maxRecords = 7;

    class TimedEvents{
        int _numOfRecords = 0;
        std::chrono::steady_clock::time_point _startTime;
        std::chrono::steady_clock::time_point _endTime;
        struct {
            std::string _eventName;
            std::string _unitsOfTime;
            std::chrono::steady_clock::duration _duration;
        } events[maxRecords];

        public:
        TimedEvents() = default;
        void startClock();
	void stopClock();
	void recordEvent(const char*);
        friend std::ostream& operator<<(std::ostream&, const TimedEvents&);
    };
}

#endif
