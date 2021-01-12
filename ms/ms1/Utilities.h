
// Date of completion:March 16th, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#pragma once
#include <string>

#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H

    class Utilities
    {
        static size_t m_widthField;
        static char m_delimiter;

    public:

        void setFieldWidth(size_t newWidth);
        size_t getFieldWidth() const;
        std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
        static void setDelimiter(char newDelimiter);
        static char getDelimiter();

    };

#endif
