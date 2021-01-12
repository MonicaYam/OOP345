
#include <iomanip>
#include "TimedEvents.h"

using namespace std;
namespace sdds{

        void TimedEvents::startClock(){
            _startTime = std::chrono::steady_clock::now();
        }

	void TimedEvents::stopClock(){
            _endTime = std::chrono::steady_clock::now();
        }

	void TimedEvents::recordEvent(const char* eventName){
	    if( _numOfRecords < maxRecords){
            	events[_numOfRecords]._eventName = eventName;
            	events[_numOfRecords]._unitsOfTime = "nanoseconds";
            	events[_numOfRecords]._duration = chrono::duration_cast<std::chrono::nanoseconds>(_endTime - _startTime);
            
            	++_numOfRecords;
	    }
       }

        ostream& operator<<(ostream& ost, const TimedEvents& src){
            ost << "--------------------------" << endl;
            ost << "Execution Times:" << endl;
            ost << "--------------------------" <<endl;

            for( int i = 0; i < src._numOfRecords; ++i){
                ost << setw(20) << left 
		            << src.events[i]._eventName
		            << setw(12) << right 
                    << src.events[i]._duration.count() << " "
                    << src.events[i]._unitsOfTime << endl;
            }

            ost << "--------------------------" <<endl;

            return ost;
        }

}


