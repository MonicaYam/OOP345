#include "SpellChecker.h"
#include <iostream>
#include <fstream>
namespace sdds
{

	SpellChecker::SpellChecker(const char* filename) {
		if (filename != nullptr) {
			std::ifstream file(filename);
			if (!file)
			{
				throw ("EXCEPTION: Bad file name!\n");
			}
			else {
				int i = 0;
				size_t c = 0;
				std::string word;
				// count how many records are in the file
				do
				{
					std::getline(file, word);

					if (file)
					{
						c = word.find_first_of(" ");
						if (c != std::string::npos) {
							m_badWords[i] = word.substr(0, c);
							word.erase(0, c);

							c = word.find_first_not_of(" ");
							m_goodWords[i] = word.substr(c);
							++i;
						}
					}
				} while (file);


				file.close();
			}
		}


	}

	void SpellChecker::operator()(std::string& text) {
		bool found = false;
		size_t firstPlace;
		for (int i = 0; i < 5 && !found; ++i) {
			//for(int i=0; i < )

			firstPlace = 0;
			while((firstPlace = text.find(m_badWords[i], firstPlace)) != std::string::npos){
				text.replace(firstPlace, m_badWords[i].length(), m_goodWords[i]);
			}

		}

	}
}