// Name:
// Seneca Student ID:
// Seneca email:
// Date of completion:
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_EVENT_H
#define SDDS_EVENT_H

#include <iostream>
#include <cstring>
#include <iomanip> 

extern size_t g_sysClock;

namespace sdds 
{
    const int MAX_CHAR = 127;

    class Event{

        private:
        char descEvent[128];
	size_t time;

	void setTime();
        void displayTime();
        bool isDescEmpty(const char *desc);

        public:
            Event();  //Default Constructor
            void display();
            void setDescription(const char *desc);
        
    };
}
#endif 
