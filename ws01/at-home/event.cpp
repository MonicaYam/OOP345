
// Date of completion: January 17th, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>

#include "event.h"
#include "event.h"

size_t g_sysClock;

namespace sdds
{

    Event::Event():_descEvent(nullptr), _time(0) {
    }

    Event::Event(const Event& src): _time(src._time) {
        if (src._descEvent) {
            int srcLength = strlen(src._descEvent);
            _descEvent = new char[srcLength +1];
            strncpy(_descEvent, src._descEvent, srcLength);
            _descEvent[srcLength] = '\0';
        }
        else {
            _descEvent = nullptr;

        }
    }
    Event::~Event() {
            delete[] _descEvent;
    }


    void Event::display()const {
        static size_t COUNTER = 1;
        if (isDescEmpty(_descEvent)) {
            std::cout << std::setw(3) << COUNTER << ". [ No Event ]" << std::endl;
        }
        else {

            std::cout << std::setw(3) << COUNTER << ". "
                << std::setw(2) << std::setfill('0') << calculateHours() << ":"
                << std::setw(2) << calculateMinutes() << ":"
                << std::setw(2) << calculateSeconds()
                << " -> " << _descEvent << std::endl;

            std::cout << std::setfill(' ');

        }


        COUNTER++;
    }

    int Event::calculateHours()const {
        return _time / 3600;
    }

    int Event::calculateMinutes() const {
        return (_time % 3600) / 60;
    }

    int Event::calculateSeconds() const {
        return (_time % 3600) % 60;
    }



    void Event::setDescription(const char* srcDesc) {
        delete[] _descEvent;
        if (!isDescEmpty(srcDesc)) {
            int srcLength = strlen(srcDesc);
            _descEvent = new char[srcLength + 1];
            strncpy(_descEvent, srcDesc, srcLength);
            _descEvent[srcLength] = '\0';

        }
        else {
            _descEvent = nullptr;
        }

        setTime();
    }


    bool Event::isDescEmpty(const char* desc) const {
        bool result = false;
        if (desc == NULL || strlen(desc) == 0) {
            result = true;
        }

        return result;
    }

    void Event::setTime() {
        _time = ::g_sysClock;
    }


    Event& Event::operator=(const Event& src) {
        if (_descEvent) {
            delete[] _descEvent;
        }

        if (this != &src && src._descEvent) {
            _time = src._time;
            _descEvent = new char[strlen(src._descEvent) + 1];
            strcpy(_descEvent, src._descEvent);
        }
        return *this;
    }
}
