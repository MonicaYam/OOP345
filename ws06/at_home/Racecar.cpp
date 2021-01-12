
// Date of completion:March 4th, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <sstream>
#include <string>
#include "Racecar.h"

using namespace std;
namespace sdds
{
	Racecar::Racecar() : m_booster{0.0}{}

	Racecar::Racecar(std::istream& in):Car(in)
	{
		string strRaceCarInfo;
		getline(in, strRaceCarInfo, ',');

		try
		{
			m_booster = stod(strRaceCarInfo);
		}
		catch (...)
		{
			throw "Invalid record!";
		}
	}

	void Racecar::display(std::ostream& out) const
	{
		Car::display(out);
		out << "*" ;
	}


	double Racecar::topSpeed() const
	{
		return Car::topSpeed() * (1.0 + m_booster);
	}
}
