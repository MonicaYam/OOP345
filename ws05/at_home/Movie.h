#pragma once
#include <string>
#include <ostream>

#ifndef _SDDS_MOVIE_H
#define _SDDS_MOVIE_H
namespace sdds
{
	class Movie
	{
		std::string m_movieTitle;
		std::string m_movieDesc;
		size_t m_moviePublishedYear;

	public:
		Movie() :m_movieTitle(""), m_movieDesc(""), m_moviePublishedYear(0) {}
		Movie(const std::string& strMovie);
		const std::string& title() const;
		template <typename T>
		void fixSpelling(T spellChecker) {
			spellChecker(m_movieTitle);
			spellChecker(m_movieDesc);
		}

		friend std::ostream& operator<<(std::ostream&, const Movie&);

	};


}
#endif