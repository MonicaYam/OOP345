#pragma once

// Date of completion:February 4th, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H
#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <string> 
#include <iostream> 
namespace sdds
{
	class Reservation
	{
		char* reserveID = nullptr;
		std::string reserveName = "";
		std::string email = "";
		int partyPpl = 0;
		int day = 0;
		int hours = 0;

	public:
		Reservation() = default;
		Reservation(const std::string& res);
		//setter
		void setID(const char*, size_t);
		void setName(std::string&);
		void setEmail(std::string&);
		void setPartyPpl(int&);
		void setDay(int&);
		void setHours(int&);

		//getter
		char* getID() const;
		std::string getName() const;
		std::string getEmail() const;
		int getPartyPpl() const;
		int getDay() const;
		int getHours() const;

		friend std::ostream& operator<<(std::ostream&, const Reservation&);
	};
}

#endif
