#include "Workstation.h"

using namespace std;
Workstation::Workstation(const string& str):Station(str)
{
	m_pNextStation = nullptr;
}

void Workstation::runProcess(ostream& os)
{
    //If there are CustomerOrders in the queue, 
    //this function fills the order in the front at the current Workstation.
    if(!m_orders.empty()){
        m_orders.front().fillItem(*this, os);
    }

} 

bool Workstation::moveOrder()
{
     bool result = false;
    // if the order at the front of the queue doesn't require service at the current station
     if(!m_orders.empty() && m_pNextStation && m_orders.front().isItemFilled(getItemName())){
	*m_pNextStation += move(m_orders.front());
	m_orders.pop_front();
	result = true;
    }

    return result;
}

void Workstation::setNextStation(Station& station)
{
   m_pNextStation = (Workstation*)&station;
}
   
const Workstation* Workstation::getNextStation() const
{
    return m_pNextStation;
}

bool Workstation::getIfCompleted(CustomerOrder& order)
{
    //places it in the parameter and returns true; otherwise returns false.
    // If the CustomerOrder queue is empty, returns false.
    bool result = false;
    // if the order at the front of the queue is completed, this function removes from the queue
    if(!m_orders.empty() && m_orders.front().isOrderFilled()){
        order = move(m_orders.front());
        m_orders.pop_front();
        result = true;
    }

    return result;
}

void Workstation::display(ostream& os)
{
    os << getItemName() << " --> ";
    if(m_pNextStation != nullptr){
        os << getNextStation()->getItemName();
    }else{
	os << "END OF LINE";
    }

    os << endl;
}

Workstation& Workstation::operator+=(CustomerOrder&& order)
{
    m_orders.push_back(move(order));
    return *this;
}

