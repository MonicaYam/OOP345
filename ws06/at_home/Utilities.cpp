
// Date of completion:March 4th, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <sstream>
#include <algorithm>
#include "Utilities.h"
#include "Racecar.h"
#include "Car.h"

using namespace std;
namespace sdds
{
	Vehicle* createInstance(std::istream& in)
	{
		stringstream ss;

		string strCarInfo, temptype;
		getline(in, temptype, ',');

		getline(in, strCarInfo);


		if (!strCarInfo.empty())
		{

			temptype.erase(remove(temptype.begin(), temptype.end(), ' '), temptype.end());

			char type = temptype.at(0);

			ss << strCarInfo;
			switch (type)
			{
			case 'C':
			case 'c':
				return new Car(ss);
				break;
			case 'R':
			case 'r':
				return new Racecar(ss);
				break;
			default:
				throw type;
				return nullptr;
				break;
			}
		}


		return nullptr;
	}
}
