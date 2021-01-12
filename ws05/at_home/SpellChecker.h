#pragma once
#include <string>

#ifndef _SDDS_SPELLCHECKER_H
#define _SDDS_SPELLCHECKER_H
namespace sdds
{
	class SpellChecker
	{
		std::string m_badWords[5];
		std::string m_goodWords[5];

	public:
		SpellChecker(const char* filename);
		void operator()(std::string& text);
	};


}

#endif