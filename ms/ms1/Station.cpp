
// Date of completion:March 16th, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <string>
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Utilities.h"
#include "Station.h"

using namespace std;
    size_t Station::m_widthField = 0;
    size_t Station::id_generator = 0;
    Station::Station(const std::string line)
    {
        bool result;

        Utilities u;
        char delimiter = u.getDelimiter();

	
        m_stationId = ++id_generator;

        size_t endPos, beginPos;
        endPos = line.find(delimiter);
        m_itemName = line.substr(0, endPos);

        beginPos = endPos + 1;
        endPos = line.find(delimiter, beginPos);
        m_serialNumber = stoi(u.extractToken(line,beginPos, result));

        beginPos = endPos + 1;
        endPos = line.find(delimiter, beginPos);
        m_qty = stoi(u.extractToken(line, beginPos, result));

        beginPos = endPos + 1;
        m_desc = u.extractToken(line, beginPos, result);

        if (m_widthField < m_itemName.length())
        {
            m_widthField = m_itemName.length();
        }
    }
    const std::string& Station::getItemName() const
    {
        return m_itemName;
    }
    unsigned int Station::getNextSerialNumber()
    {
        return m_serialNumber++;
    }
    unsigned int Station::getQuantity() const
    {
        return m_qty;
    }
    void Station::updateQuantity()
    {
        if (m_qty > 0)
        {
            m_qty--;
        }

    }


    void Station::display(std::ostream& os, bool full) const
    {
        os << "[" << std::setfill('0') << std::setw(3) << right << m_stationId
            << "] Item: " << std::setfill(' ') << std::setw(m_widthField) << left << m_itemName
            << " [" << std::setfill('0') << std::setw(6) << right << m_serialNumber << "]";
        if (full)
        {
            os << std::setfill(' ') << " Quantity: " << setw(m_widthField) << left << m_qty
                << " Description: " << m_desc;
        }

        os << endl;
    }
