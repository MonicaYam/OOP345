#include <algorithm>
#include <iomanip>
#include <list>
#include <deque>
#include <vector>
#include <stack>

#include "CustomerOrder.h"
#include "Utilities.h"

using namespace std;

size_t CustomerOrder::m_widthField = 0;

CustomerOrder::CustomerOrder()
{
        m_name    = "";
        m_product = "";
        m_cntItem = 0u;
        m_lstItem = nullptr;
}

CustomerOrder::CustomerOrder(std::string line)
{
	Utilities u;
	bool result = false;
	size_t endPos, beginPos;
	char delimiter = u.getDelimiter();

	endPos = line.find(delimiter);
	m_name = line.substr(0, endPos);

	beginPos = endPos + 1;
	endPos = line.find(delimiter, beginPos);
	m_product = u.extractToken(line, beginPos, result);	

	m_cntItem = std::count(line.begin(), line.end(), delimiter) - 1;
	if(m_cntItem > 0){
		//double pointer of item
		m_lstItem = new Item*[m_cntItem];
		for(size_t i = 0u; i < m_cntItem; ++i){
			beginPos = endPos + 1;
			endPos = line.find(delimiter, beginPos);
			m_lstItem[i] = new Item(u.extractToken(line, beginPos, result));
		}		
	}

	if(m_widthField < u.getFieldWidth()){
		m_widthField = u.getFieldWidth();
	}
}

CustomerOrder::CustomerOrder(CustomerOrder& co){
	throw "Copy Constructor is not allow in this class.";
}

CustomerOrder::CustomerOrder(CustomerOrder&& co) noexcept 
{
	*this = move(co);
}

CustomerOrder& CustomerOrder::operator=(CustomerOrder&& co) noexcept
{
	if(this != &co){
	    if(m_lstItem){
	    	for(size_t i = 0u; i < m_cntItem; i++) {
	    	    delete m_lstItem[i];
	    	}
	    	delete[] m_lstItem;
	    }
	    m_name = co.m_name;
	    m_product = co.m_product;	
	    m_cntItem = co.m_cntItem;
	    m_widthField = co.m_widthField;
	    m_lstItem = co.m_lstItem;

	    co.m_name = "";
	    co.m_product = "";
	    co.m_cntItem = 0u;
	    co.m_lstItem = { nullptr };
	}

	return *this;
}

CustomerOrder::~CustomerOrder()
{
	for(size_t i = 0u; i < m_cntItem; ++i){
		delete m_lstItem[i];
	}

	delete[] m_lstItem;
	m_lstItem = nullptr;
}

bool CustomerOrder::isOrderFilled() const
{
	size_t i = 0u;
	bool temp = true;
	do{
	    if(m_lstItem[i]->m_isFilled == false){
	        temp = false;
	    }
	    i++;
	} while(i < m_cntItem && temp == true);

	return temp;
}

bool CustomerOrder::isItemFilled(const std::string& itemName)
{
	bool result = false;
	for(size_t i = 0u; i < m_cntItem; ++i){
	    if(itemName.compare(m_lstItem[i]->m_itemName) == 0){
		result = true;
	    }
	}

	return result;
}

void CustomerOrder::fillItem(Station& station, std::ostream& os)
{
	for(size_t i = 0u; i < m_cntItem; ++i){
	    if(m_lstItem[i]->m_itemName.compare(station.getItemName()) == 0){
		if(station.getQuantity() > 0){
		    station.updateQuantity();
		    m_lstItem[i]-> m_serialNumber = station.getNextSerialNumber();
		    m_lstItem[i]-> m_isFilled = true;
		    os << string(4,' ') << "Filled " << m_name << ", " << m_product 
                       << " [" << station.getItemName() <<"]" << endl;
		}else{
		    os << string(4, ' ') << "Unable to fill" << m_name << ", " << m_product
                       << " [" << station.getItemName() <<"]" <<endl;
		}
	    }	
	}
}

void CustomerOrder::display(std::ostream& os) const{

    os << m_name << " - " << m_product << endl;
    for(size_t i = 0u; i < m_cntItem; ++i){	
        os << "[" << setw(6) << setfill('0') << right << m_lstItem[i]->m_serialNumber <<  "] " 
           << setw(m_widthField) << setfill(' ') << left << m_lstItem[i]->m_itemName << " - ";
	if(m_lstItem[i]->m_isFilled){ 
	    os << "FILLED";
	}else{
	    os << "MISSING";
	}
	
	os << std::endl;
    }
    std::stack<double> prices; // initially empty 

    prices.push(10.43); // add 10.43
    prices.push(20.54); // add 20.54
    prices.push(32.43); // add 32.43
    prices.top() = 5.41;

    while (!prices.empty()) {
        std::cout << prices.top() << "  ";
        prices.pop();
    }
    std::cout << std::endl;
}
