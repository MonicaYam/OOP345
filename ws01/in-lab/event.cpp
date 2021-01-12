
// Date of completion: January 16th, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <fstream>
#include <iostream>

#include "event.h"
#include "event.h"

size_t g_sysClock;

namespace sdds 
{
    static int COUNTER = 0;
    
    Event::Event(){
        descEvent[0] = '\0';
    }
  


    void Event::display(){
        COUNTER++;
        if(isDescEmpty(descEvent)){
            std::cout << std::setw(3) << COUNTER << ". [ No Event ]"<< std::endl;
        }else{
            displayTime();
        }
    }

    
    void Event::setDescription(const char *desc){
        if(!isDescEmpty(desc)){
            strncpy(descEvent, desc, MAX_CHAR);
        }
        else{
            descEvent[0] = '\0';
        }
	
	setTime();
    }

    void Event::displayTime(){
        size_t tempTime = time;
        int h,m,s;

        h = tempTime / 3600;
        tempTime %= 3600;

        m = tempTime / 60;
        tempTime %= 60;

        s = tempTime;

        std::cout << std::setw(3) << COUNTER << ". "
                  << std::setw(2) << std::setfill('0') << h << ":" 
                  << std::setw(2) << m << ":"
                  << std::setw(2) << s
                  << " -> " << descEvent << std::endl;
 
        std::cout << std::setfill(' ');
    }

    bool Event::isDescEmpty(const char *desc){
        bool result = false;
            if( desc == NULL || strlen(desc) == 0){
                result = true;
            }

        return result;
    }
 
    void Event::setTime(){
        time = ::g_sysClock;
    }   
}
