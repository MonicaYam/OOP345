
// Date of completion:March 16th, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <string>
#include "Utilities.h"

using namespace std;

size_t Utilities::m_widthField = 1;
char Utilities::m_delimiter = 1;

        // --sets the field width of the current object to the value of the parameter
        void Utilities::setFieldWidth(size_t newWidth)
        {
            m_widthField = newWidth;
        }
        //--returns the field width of the current object
        size_t Utilities::getFieldWidth() const
        {
            return m_widthField;
        }

        /*--extracts tokens from the first parameter
        This function uses the delimiter to extract the next token from str starting at next_pos.
            If successful, it returns the extracted token foundand sets more to true; false otherwise.
            This function reports an exception if there are two delimiters with no token between them.
            This function updates the current object's m_widthField data member if its current value is less than the size of the token extracted.
            Note: str represents a single line read from an input file*/
        std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
        {
            int beginIdx = str.find(m_delimiter, next_pos);
            string extToken = str.substr(next_pos, beginIdx - next_pos);

            if (extToken.compare("") != 0)
            {
                more = true;
                if (m_widthField < extToken.size())
                {
                    setFieldWidth(extToken.size());
                }
                return extToken;
            }
            else
            {
                more = false;
                throw "Exception";
            }
        }

        //--sets the delimiter for this class to the character received
        void Utilities::setDelimiter(char newDelimiter)
        {
            m_delimiter = newDelimiter;
        }

        //--returns the delimiter character.
        char Utilities::getDelimiter()
        {
            return m_delimiter;
        }
