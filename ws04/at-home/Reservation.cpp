
// Date of completion:February 4th, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include "Reservation.h"
#include <iomanip> 
#include <cstring>
namespace sdds
{
	Reservation::Reservation(const std::string& res) {
		std::string targetTxt = res;

		if (res != "") {
			std::string tempStr[5];

			size_t c, i = 0;

			while ((c = targetTxt.find_first_of(" ")) != std::string::npos) {
				targetTxt.erase(c, 1);
			}

			//id
			size_t place = targetTxt.find(":");
			tempStr[i] = targetTxt.substr(0, place);
			setID(tempStr[i++].c_str(), place);

			targetTxt.erase(0, place + 1);

			while ((place = targetTxt.find(",")) != std::string::npos) {
				tempStr[i++] = targetTxt.substr(0, place);
				targetTxt.erase(0, place + 1);
			}


			setName(tempStr[1]);
			setEmail(tempStr[2]);
			int number = std::stoi(tempStr[3]);
			setPartyPpl(number);
			number = std::stoi(tempStr[4]);
			setDay(number);
			number = std::stoi(targetTxt.substr(0));
			setHours(number);

		}
	}

	std::ostream& operator<<(std::ostream& os, const Reservation& reserve) {
		os << "Reservation " << reserve.reserveID << ": "
			<< std::setw(10) << std::right << reserve.reserveName << " "
			<< std::setw(20) << std::left << " <" + reserve.email + ">" << "    ";

		if (reserve.hours >= 6 && reserve.hours <= 9) {
			os << " Breakfast on day ";
		}
		else if (reserve.hours >= 11 && reserve.hours <= 15) {
			os << " Lunch on day ";
		}
		else if (reserve.hours >= 17 && reserve.hours <= 21) {
			os << " Dinner on day ";
		}
		else {
			os << " Drinks on day ";
		}
		os << reserve.day << " @ " << reserve.hours << ":00 for " << reserve.partyPpl << " people." << std::endl;

		return os;
	}


	//setter
	void Reservation::setID(const char* tempChar, size_t idx) {
		reserveID = new char[idx + 1];
		strncpy(reserveID, tempChar, idx);
		reserveID[idx] = '\0';
	}
	void Reservation::setName(std::string& name) {
		reserveName = name;
	}
	void Reservation::setEmail(std::string& tempEmail) {
		email = tempEmail;
	}
	void Reservation::setPartyPpl(int& tempPpl) {
		partyPpl = tempPpl;
	}
	void Reservation::setDay(int& tempDay) {
		day = tempDay;
	}
	void Reservation::setHours(int& tempHours) {
		hours = tempHours;
	}

	//getter
	char* Reservation::getID() const{
		return reserveID;
	}
	std::string Reservation::getName() const {
		return reserveName;
	}
	std::string Reservation::getEmail() const{
		return email;
	}
	int Reservation::getPartyPpl() const{
		return partyPpl;
	}
	int Reservation::getDay() const{
		return day;
	}
	int Reservation::getHours() const {
		return hours;
	}
}

