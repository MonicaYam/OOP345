

// Date of completion:February 10th, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "Reservation.h"
#include "Restaurant.h"
//composition to reservation
#include <cstring>
namespace sdds
{
	Restaurant::Restaurant(Reservation* reservations[], size_t cnt) {
			maxSize = cnt;
			reserve = new Reservation[cnt];
			for (size_t i = 0; i < cnt; i++) {
				setValue(*reservations[i], i);
			}
	}

	Restaurant::Restaurant(const Restaurant& res) {
		if (this != &res) {
			maxSize = res.size();
			reserve = new Reservation[maxSize];

			for (size_t i = 0; i < maxSize; i++) {
				setValue(res.reserve[i], i);
			}
		}

	}

	Restaurant::Restaurant(Restaurant&& res) {

		if (this != &res) {
			maxSize = res.size();
			reserve = new Reservation[maxSize];

			for (size_t i = 0; i < maxSize; i++) {
				setValue(res.reserve[i], i);
			}


			delete[] res.reserve;
			res.reserve = nullptr;
		}
	}


	size_t Restaurant::size() const {
		return maxSize;
	}


	void Restaurant::setValue(Reservation res, int i) {
		std::string tempStr;
		int tempSize;
		reserve[i].setID(res.getID(), strlen(res.getID()));
		tempStr = res.getName();
		reserve[i].setName(tempStr);
		tempStr = res.getEmail();
		reserve[i].setEmail(tempStr);

		tempSize = res.getPartyPpl();
		reserve[i].setPartyPpl(tempSize);
		tempSize = res.getDay();
		reserve[i].setDay(tempSize);
		tempSize = res.getHours();
		reserve[i].setHours(tempSize);
	}

	std::ostream& operator<<(std::ostream& os, const Restaurant& src) {
		os << "--------------------------" << std::endl;
		os << "Fancy Restaurant" << std::endl;
		os << "--------------------------" << std::endl;

		if (src.reserve != nullptr) {
			for (size_t i = 0; i < src.size(); i++) {
				os << src.reserve[i];
			}
		}
		else {
			os << "The object is empty!" << std::endl;
		}

		os << "--------------------------" << std::endl;
		return os;
	}
}
