
// Date of completion:March 4th, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#pragma once

#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
#include <iostream>
#include <vector>
#include "Vehicle.h"

using namespace std;
namespace sdds
{
	Vehicle* createInstance(std::istream& in);
}

#endif