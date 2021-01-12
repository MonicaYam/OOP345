#pragma once
// Date of completion:February 10th, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#pragma once
#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H
namespace sdds
{
	class Reservation;
	class ConfirmationSender
	{
		Reservation** _csReservation;
		size_t arraySize;


	public:
		ConfirmationSender() :_csReservation(nullptr), arraySize(0) {};
		ConfirmationSender(const ConfirmationSender&); //Copy constructor
		ConfirmationSender(ConfirmationSender&&); //Move constructor

		int found(const Reservation& res);
		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);

		ConfirmationSender& operator=(const ConfirmationSender&&);
		friend std::ostream& operator<<(std::ostream&, const ConfirmationSender&);


	};

}
#endif
