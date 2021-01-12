
// Date of completion:March 6th, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#pragma once
#include <string>
#include <iostream>
#include <vector>
namespace sdds
{
	struct Song
	{
		std::string artist;
		std::string title;
		std::string album;
		double      price;
		size_t		year;
		size_t		lengthOfTheSong;
	};

	class SongCollection
	{
		std::vector<Song> songs;
	public:
		std::string trim(std::string);
		SongCollection(std::string);
		void display(std::ostream& out) const;
	};

	std::ostream& operator<<(std::ostream& out, const Song& theSong);
}
