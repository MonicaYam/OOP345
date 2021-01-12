
// Date of completion:March 4th, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.


#pragma once

#ifndef SDDS_CARS_H
#define SDDS_CARS_H
#include <iostream>
#include <string>
#include "Vehicle.h"

using namespace std;
namespace sdds
{
	enum class  Condition
	{
		New, Used, Broken
	};

	class Car : public Vehicle
	{
		string m_maker;
		Condition m_condition;
		double m_topSpeed;
	public:
		Car();
		Car(istream& is);
		~Car();

		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream& out) const;

	};
}

#endif