
// Date of completion: January 17th, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_EVENT_H
#define SDDS_EVENT_H

extern size_t g_sysClock;

namespace sdds
{
    class Event
    {

    private:
        char* _descEvent;
        size_t _time;

        void setTime();
        int calculateHours()const;
        int calculateMinutes()const;
        int calculateSeconds() const;
        bool isDescEmpty(const char* desc) const;

    public:
        Event();  //Default Constructor
        Event(const Event& src);
        ~Event();
        void display()const;
        void setDescription(const char* desc);
        Event& operator=(const Event& src);

    };

}
#endif 

