
// Date of completion:March 16th, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#pragma once
#include <string>

#ifndef SDDS_STATION_H
#define SDDS_STATION_H

    class Station
    {
        size_t m_stationId;
        std::string m_itemName;
        std::string m_desc;
        size_t m_serialNumber;
        size_t m_qty;

        static size_t m_widthField;
        static size_t id_generator;
    public:
        Station(const std::string);
        const std::string& getItemName() const;
        unsigned int getNextSerialNumber();
        unsigned int getQuantity() const;
        void updateQuantity();
        void display(std::ostream& os, bool full) const;

    };

#endif
