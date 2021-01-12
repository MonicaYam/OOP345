
// Date of completion:March 4th, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.


#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include "Car.h"

using namespace std;
namespace sdds
{
	Car::Car() :m_maker{}, m_condition{}, m_topSpeed{ 0.0 }{}
	Car::Car(istream& is)
	{
		string  tempCondition, tempSpeed, tempBooster, strCarInfo;
		vector<string> tempArray;
		int i = 0;
		while (i < 3 && getline(is, strCarInfo, ',') )
		{
			//strCarInfo.erase(remove(strCarInfo.begin(), strCarInfo.end(),' '), strCarInfo.end());

			int beginPos = strCarInfo.find_first_not_of(" ");
			if (strCarInfo != std::string() && !strCarInfo.empty() && beginPos > 0)
			{
				strCarInfo = strCarInfo.substr(beginPos);
			}

			size_t endPos = strCarInfo.find_last_not_of(" ");
			if (endPos != std::string::npos && strCarInfo.length() > endPos)
			{
					strCarInfo = strCarInfo.substr(0, endPos+1);
			}
			tempArray.push_back(strCarInfo);
			i++;
		}

		m_maker = tempArray[0];

		if (tempArray[1] == std::string() || tempArray[1].at(0) == 'n' || tempArray[1].at(0) == ' ')
		{
			m_condition = Condition::New;

		}
		else if (tempArray[1].at(0) == 'u')
		{
			m_condition = Condition::Used;
		}
		else if(tempArray[1].at(0) == 'b') //condition.at(0) == 'b'
		{
			m_condition = Condition::Broken;
		}
		else
		{
			throw "Invalid record!";
		}

		try
		{
			m_topSpeed = stod(tempArray[2]);
		}
		catch (...)
		{
			throw "Invalid record!";
		}

	}

	Car::~Car()
	{
	}

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
			<< " |" ;

	}

}



