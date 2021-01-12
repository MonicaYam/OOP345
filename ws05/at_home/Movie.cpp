#include <iomanip>
#include "Movie.h"
namespace sdds
{

    	Movie::Movie(const std::string& strMovie) {
        std::string temp = strMovie;
        size_t place, c, i = 0;
        std::string tempStr[3];

        if (strMovie != "") {
            while (((place = temp.find(",")) != std::string::npos) && i < 2) {
                tempStr[i] = temp.substr(0, place);

                c = tempStr[i].find_first_not_of(" ");
                if (c != std::string::npos) {
                    tempStr[i].erase(0, c);
                }

                c = tempStr[i].find_last_not_of(" ");

                if (c != std::string::npos) {
                    tempStr[i].erase(c + 1);
                }

                temp.erase(0, place + 1);
                i++;
            }

            c = temp.find_first_not_of(" ");
            if (c != std::string::npos) {
                temp.erase(0, c);
            }

            c = temp.find_last_not_of(" ");

            if (c != std::string::npos) {
                temp.erase(c + 1);
            }

            m_movieTitle = tempStr[0];
            m_moviePublishedYear = std::stoi(tempStr[1]);
            m_movieDesc = temp;
        }
        else {
            m_movieTitle = "";
            m_movieDesc = "";
            m_moviePublishedYear = 0;
        }
	}

	const std::string& Movie::title() const {
		return m_movieTitle;
	}

    std::ostream& operator<<(std::ostream& os, const Movie& m) {
        os << std::setw(40) << m.title() << " | " << std::setw(4)  << m.m_moviePublishedYear << " | " << m.m_movieDesc << std::endl;
        return os;
    }
}