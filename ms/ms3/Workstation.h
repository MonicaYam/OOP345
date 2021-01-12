#include <iostream>
#include <deque>
#include <string>

#include "Station.h"
#include "CustomerOrder.h"

#ifndef WORKSTATION_H
#define WORKSTATION_H

class Workstation :public Station {
    std::deque<CustomerOrder> m_orders;
    Workstation* m_pNextStation;

public:
    Workstation(const std::string&);
    Workstation(Workstation&) = delete;
    Workstation(Workstation&&) = delete;
    Workstation& operator=(Workstation&) = delete;
    Workstation& operator=(Workstation&&) = delete;

    void runProcess(std::ostream& os);
    bool moveOrder();
    void setNextStation(Station& station);
    const Workstation* getNextStation() const;
    bool getIfCompleted(CustomerOrder& order);
    void display(std::ostream&);

    Workstation& operator+=(CustomerOrder&& order);

};

#endif

