
// Date of completion:March 16th, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <string>
#include "Utilities.h"

using namespace std;

char Utilities::m_delimiter = '|';

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
    	    string extToken;
    	    size_t beginIdx = str.find(m_delimiter, next_pos);
    	    if (beginIdx != next_pos) {
        	more = (beginIdx != string::npos) ? true : false;
        	extToken = str.substr(next_pos, beginIdx - next_pos);
        	next_pos = beginIdx + 1;
        	if (extToken.size() > m_widthField){
            		m_widthField = extToken.length();
        	}
    	    }else{
        	more = false;
        	throw "there are two delimiters with no token";
    	    }

	    return extToken;
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
