
// Date of completion:February 10th, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <cstring>
#include "Reservation.h"
#include "ConfirmationSender.h"
namespace sdds
{
	ConfirmationSender::ConfirmationSender(const ConfirmationSender& cs) {
		_csReservation = nullptr;
		arraySize = 0;

		if (this != &cs) {
			arraySize = cs.arraySize;
			_csReservation = new Reservation * [arraySize];
				_csReservation = cs._csReservation;
		}
	}


	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender&& cs) {
		std::string tempStr;
		int tempInt;
		for (size_t i = 0; i < arraySize; i++) {
			int length = strlen(cs._csReservation[i]->getID());
			_csReservation[i]->setID(cs._csReservation[i]->getID(), length);
			tempStr = cs._csReservation[i]->getName();
			_csReservation[i]->setName(tempStr);
			tempStr = cs._csReservation[i]->getEmail();
			_csReservation[i]->setEmail(tempStr);
			tempInt = cs._csReservation[i]->getPartyPpl();
			_csReservation[i]->setPartyPpl(tempInt);
			tempInt = cs._csReservation[i]->getDay();
			_csReservation[i]->setDay(tempInt);
			tempInt = cs._csReservation[i]->getHours();
			_csReservation[i]->setHours(tempInt);
		}

		return *this;
	}

	ConfirmationSender::ConfirmationSender(ConfirmationSender&& cs) {
		_csReservation = nullptr;
		arraySize = 0;

		if (this != &cs) {
			arraySize = cs.arraySize;
			_csReservation = new Reservation * [arraySize];
			for (int i = 0; i < (int)arraySize; i++) {
				_csReservation[i] = cs._csReservation[i];
				cs._csReservation[i] = nullptr;
			}

			cs.arraySize = 0;
			delete[] cs._csReservation;
		}
	}

	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) {
		int index, i = 0;
		index = found(res);
		if (index == -1) {
			Reservation** temp = new Reservation * [arraySize + 1];
			if (_csReservation != nullptr) {
				for (i = 0; i < (int)arraySize; i++) {
					temp[i] = _csReservation[i];
				}
			}

			temp[i] = (Reservation*)&res;
			arraySize++;

			delete[] _csReservation;
			_csReservation = temp;
		}
		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) {
		int i, index = found(res);
		if (index > -1) {
			Reservation** tempRes = nullptr;
			tempRes = new Reservation * [arraySize - 1];
			for (i = 0; i < (int)arraySize; i++) {
				if (i != index) {
					tempRes[i] = _csReservation[i];
				}
			}

			delete[] _csReservation;
			_csReservation = tempRes;
			arraySize--;
		}
		return *this;
	}

	int ConfirmationSender::found(const Reservation& res) {
		std::string tempOrg, tempStr = res.getID();
		bool found = false;
		int index = -1;
		for (int i = 0; i < (int)arraySize && !found; ++i) {
			tempOrg = _csReservation[i]->getID();
			if (tempOrg.substr(5, 7) == tempStr.substr(5, 7)) {
				index = i;
				found = true;
			}
		}
		return index;
	}
	std::ostream& operator<<(std::ostream& os, const ConfirmationSender& cs) {
		os << "--------------------------" << std::endl;
		os << "Confirmations to Send" << std::endl;
		os << "--------------------------" << std::endl;

		ConfirmationSender temp = cs;
		if (cs.arraySize == 0) {
			os << "The object is empty!" << std::endl;
		}
		else {
			for (size_t i = 0; i < cs.arraySize; i++) {
				os << *temp._csReservation[i];
			}
		}

		os << "--------------------------" << std::endl;
		return os;
	}

}
