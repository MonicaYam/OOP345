
// Date of completion:March 4th, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.


#include "Autoshop.h"

using namespace std;
namespace sdds
{

	Autoshop::~Autoshop()
	{
		for (auto& car : m_vehicles)
		{
			delete car;
		}
	}

	//: adds the vehicle received as parameter into the m_vehicles vector.
	Autoshop& Autoshop::operator +=(Vehicle* theVehicle)
	{
		m_vehicles.push_back(theVehicle);

		return *this;
	}
	//: iterates over the vehicles stored in m_vehicles and prints them into the parameter (use Vehicle::display()) using the format:
	void Autoshop::display(std::ostream& out) const
	{
		out << "--------------------------------" << endl;
		out << "| Cars in the autoshop!        |" << endl;
		out << "--------------------------------" << endl;


		for (auto i = m_vehicles.begin(); i != m_vehicles.end(); i++)
		{
			(*i)->display(out);
			out << endl;
		}

		out << "--------------------------------" << std::endl;
	}
}