#pragma once

// Date of completion:March 4th, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.


#pragma once

#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H
#include <iostream>
#include <vector>
#include "Vehicle.h"

using namespace std;
namespace sdds
{
	class Autoshop
	{
		//: a vector that store all the vehicles available at this autoshop.
		vector<Vehicle*> m_vehicles;
	public:
		~Autoshop();

		//: adds the vehicle received as parameter into the m_vehicles vector.
		Autoshop& operator +=(Vehicle* theVehicle);
		//: iterates over the vehicles stored in m_vehicles and prints them into the parameter (use Vehicle::display()) using the format:
		void display(std::ostream& out) const;
	};
}

#endif