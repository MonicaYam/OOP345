#pragma once

// Date of completion:February 4th, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
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
		char* getID();
		std::string getName();
		std::string getEmail();
		int getPartyPpl();
		int getDay();
		int getHours();

		friend std::ostream& operator<<(std::ostream&, const Reservation&);
	};
}
