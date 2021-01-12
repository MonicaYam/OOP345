#include <string>
#include <iostream>
#include "Station.h"

#ifndef CUSTOMERORDER_H
#define CUSTOMERORDER_H

struct Item
{
	std::string m_itemName;
	unsigned int m_serialNumber = 0;
	bool m_isFilled = false;

	Item(const std::string& src) : m_itemName(src) {};
};


class CustomerOrder{
	std::string m_name;
	std::string m_product;
	size_t m_cntItem;
	Item** m_lstItem{};
	
	static size_t m_widthField;

	public:
	CustomerOrder();
	CustomerOrder(std::string);
	CustomerOrder(CustomerOrder&);
	CustomerOrder& operator=(CustomerOrder&) = delete;
	CustomerOrder(CustomerOrder&&) noexcept;
	CustomerOrder& operator=(CustomerOrder&&) noexcept;
	~CustomerOrder();
	bool isOrderFilled() const;
	bool isItemFilled(const std::string& itemName) const;
	void fillItem(Station& station, std::ostream& os);
	void display(std::ostream& os) const;

};
#endif
