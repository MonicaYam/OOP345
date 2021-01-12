
// Date of completion:March 4th, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <sstream>
#include "Utilities.h"
#include "Car.h"

using namespace std;
namespace sdds
{
	Vehicle* createInstance(std::istream& in)
	{
		Vehicle* temp = nullptr;
		stringstream ss;

		string strCarInfo, tag;
		getline(in, strCarInfo);

		if (!strCarInfo.empty())
		{
			ss << strCarInfo;
			ss >> tag;

			if (tag.at(0) == 'c' || tag.at(0) == 'C')
			{
				temp = new Car(ss);
			}
			ss.clear();
			ss.str("");
		}
		return temp;
	}
}
