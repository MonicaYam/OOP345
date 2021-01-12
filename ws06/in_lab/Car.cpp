
// Date of completion:March 4th, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.


#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <algorithm>
#include "Car.h"

using namespace std;
namespace sdds
{
	Car::Car() :m_maker{}, m_condition{}, m_topSpeed{ 0.0 }{}
	Car::Car(istream& is)
	{
		string strCarInfo, tempCondition, tempSpeed;

		getline(is, strCarInfo);
		replace(strCarInfo.begin(), strCarInfo.end(), ',', ' ');
		stringstream ss(strCarInfo);

		ss >> m_maker >> tempCondition >> tempSpeed;

		if (tempCondition.at(0) == 'n')
		{
			m_condition = Condition::New;

		}
		else if (tempCondition.at(0) == 'u')
		{
			m_condition = Condition::Used;
		}
		else{
			//condition.at(0) == 'b'
			m_condition = Condition::Broken;
		}

		m_topSpeed = stod(tempSpeed);

		ss.clear();
		ss.str("");
	}

	Car::~Car(){}

string Car::condition() const
{
	string conditionResult = "";
	if (m_condition == Condition::New)
	{
		conditionResult = "new";
	}
	else if (m_condition == Condition::Used)
	{
		conditionResult = "used";
	}
	else if (m_condition == Condition::Broken)
	{
		conditionResult = "broken";
	}
	return conditionResult;
}

double Car::topSpeed() const
{
	return m_topSpeed;
}

void Car::display(std::ostream& out) const
{
	out << "| " << std::right << std::setw(10) << m_maker
		<< " | " << std::left << std::setw(6) << condition()
		<< " | " << std::setw(6) << std::setprecision(2) << std::fixed << topSpeed()
		<< " |" << endl;
}
}



