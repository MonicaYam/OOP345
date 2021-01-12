
// Date of completion:March 4th, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.


#pragma once

#ifndef SDDS_RACECARS_H
#define SDDS_RACECARS_H
#include <iostream>
#include <string>
#include "Car.h"

using namespace std;
namespace sdds
{
	class Racecar : public Car
	{
		double m_booster;
	public:
		Racecar();
		Racecar(std::istream& in);

		void display(std::ostream& out) const;
		double topSpeed() const;

	};
}

#endif