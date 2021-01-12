#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <list>
namespace sdds
{
	struct Song
	{
		std::string m_artist;
		std::string m_title;
		std::string m_album;
		double      m_price;
		size_t		m_year;
		size_t		lengthOfTheSong;
	};

	class SongCollection
	{
		std::vector<Song> songs;
	public:
		SongCollection(std::string);
		std::string trim(std::string);
		void display(std::ostream& out) const;
		void sort(std::string);
		void cleanAlbum();
		bool inCollection(std::string) const;
		std::list<Song> getSongsForArtist(std::string) const;
	};

	std::ostream& operator<<(std::ostream& out, const Song& theSong);
}
