#include <iostream>
#include <string>
#include <vector>
#include <deque>

#include "CustomerOrder.h"
#include "Workstation.h"

#ifndef LINEMANAGER_H
#define LINEMANAGER_H

class LineManager
{
    std::vector<Workstation*> AssemblyLine;
    std::vector<Workstation*> AssemblySortedLine;
    std::deque<CustomerOrder> ToBeFilled;
    std::deque<CustomerOrder> Completed;
    size_t m_cntCustomerOrder;
    size_t m_cntCallRun = 1;

    public:
    LineManager(const std::string&, std::vector<Workstation*>&, std::vector<CustomerOrder>&);
    bool run(std::ostream&);
    void displayCompletedOrders(std::ostream&) const;
    void displayStations() const;
    void displayStationsSorted() const;
};

#endif
