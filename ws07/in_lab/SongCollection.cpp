
// Date of completion:March 6th, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <fstream>
#include <iomanip>
#include <iterator>
#include <algorithm>
#include "SongCollection.h"

using namespace std;
namespace sdds
{
	string SongCollection::trim(string trimStr)
	{
		std::string temp;
		if (trimStr.find_first_not_of(' ') != std::string::npos)
		{
			int beginIdx = trimStr.find_first_not_of(" ");
			int endIdx = trimStr.find_last_not_of(" ");
			if (trimStr.find_last_not_of(" ") != std::string::npos)
			{
				temp = trimStr.substr(beginIdx, endIdx - beginIdx + 1);
			}
			else
			{
				temp = "";
			}
		}
		return temp;
	}

	SongCollection::SongCollection(std::string fName)
	{
		ifstream file(fName);
		if (file)
		{
			vector<string> tempSongInfos;
			string tempArtist, tempTitle, tempAlbum, tempPrice, tempYear, tempLength;
			int strEndPos = 25;

			while (file)
			{

				Song song;
				string line;

				getline(file, line);
				if (!line.empty())
				{
					string tempTitle = trim(line.substr(0, strEndPos));
					song.title = tempTitle;
					song.artist = trim(line.substr(25, strEndPos));
					song.album = trim(line.substr(50, strEndPos));


					try
					{
						song.year = std::stoi(line.substr(75, 5));

					}
					catch (...)
					{
						song.year = 0;
					}

					song.lengthOfTheSong = std::stoi(line.substr(80, 5));
					song.price = stod(line.substr(85));

					songs.push_back(song);

				}
			}

			file.close();
		}
		else
		{
			throw "fstream error";
		}

	}
	void SongCollection::display(std::ostream& out) const
	{
		for_each(songs.begin(), songs.end(), [&out](const Song& song)
		{
			out << song << endl;
		});

	}

	std::ostream& operator<<(std::ostream& out, const Song& theSong)
	{
		string songYear = "";

		if (theSong.year > 0)
		{
			songYear = to_string(theSong.year);
		}

		out << "| " << left << setw(20) << theSong.title << " | "
			<< left << setw(15) << theSong.artist << " | "
			<< left << setw(20) << theSong.album << " | "
			<< setw(6) << right << songYear << " | "
			<<  (theSong.lengthOfTheSong % 3600) / 60 << ":" << setw(2) << setfill('0') << theSong.lengthOfTheSong % 60 << " | " 
			<< std::fixed << std::setprecision(2) << theSong.price << " |"
			<< setfill(' ');


		return out;
	}
}
