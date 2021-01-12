
// Date of completion:February 10th, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#pragma once
#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H

#include <iostream>
namespace sdds
{
	class Reservation;

	class Restaurant
	{
		Reservation* reserve = nullptr;
		size_t maxSize = 0;
	public:
		Restaurant(){};
		Restaurant(Reservation* reservations[], size_t cnt);
		Restaurant(const Restaurant&); //Copy constructor
		Restaurant(Restaurant&&); //Move constructor
		//Restaurant& operator=(const Restaurant&&); //Move assignment operator

		size_t size() const;

		void setValue(Reservation res, int);
		friend std::ostream& operator<<(std::ostream&, const Restaurant&);
	};

}
#endif
