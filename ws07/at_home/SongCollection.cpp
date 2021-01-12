#include <fstream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include "SongCollection.h"

using namespace std;
namespace sdds
{

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
					song.m_title =  trim(line.substr(0, strEndPos));
					song.m_artist = trim(line.substr(25, strEndPos));
					song.m_album = trim(line.substr(50, strEndPos));


					try
					{
						song.m_year = std::stoi(line.substr(75, 5));

					}
					catch (...)
					{
						song.m_year = 0;
					}

					song.lengthOfTheSong = std::stoi(line.substr(80, 5));
					song.m_price = stod(line.substr(85));

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


	void SongCollection::display(std::ostream& out) const
	{
                for_each(songs.begin(), songs.end(), [&out](const Song& song){
				out << song << endl;

                });

		int totalLength = accumulate(songs.begin(), songs.end(), 0, [](int total, const Song& song){
				return total + song.lengthOfTheSong;
		});

		int hour = totalLength / 3600;
		int min = (totalLength % 3600) / 60;
		int second = totalLength % 60;

		out << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');
		out << "| " << std::setw(77) << std::right << "Total Listening Time: " << hour << ":" << min << ":" << second << " |" << std::endl;


	}


	void SongCollection::sort(string sortTarget)
	{
		if (sortTarget.compare("title") == 0)
		{
			std::sort(songs.begin(), songs.end(), [](Song& a, Song& b)
				{
					return a.m_title < b.m_title;
				}
			);
		}
		else if (sortTarget.compare("length") == 0)
		{
			std::sort(songs.begin(), songs.end(), [](Song& a, Song& b)
				{
					return a.lengthOfTheSong < b.lengthOfTheSong;
				}
			);
		}
		else if (sortTarget.compare("album") == 0)
		{
			std::sort(songs.begin(), songs.end(), [](Song& a, Song& b)
				{
					return a.m_album < b.m_album;
				}
			);
		}
	}


	void SongCollection::cleanAlbum()
	{

		auto clear = [&](Song& song)
		{
			//if album name is [none]
			if (song.m_album == "[None]") {
				song.m_album = "";
			}		
		};

		for_each(songs.begin(), songs.end(), clear);
	}


	bool SongCollection::inCollection(std::string artistName) const
	{
		auto find = find_if(songs.begin(), songs.end(), [artistName](const Song& song){
                        return song.m_artist == artistName;
		});

		return find != songs.end();
	}

	std::list<Song> SongCollection::getSongsForArtist(string artistName) const
	{
		int count = count_if(songs.begin(), songs.end(), [artistName](const Song& song){
			return song.m_artist == artistName;
		});

		list<Song> songList(count);

		std::copy_if(songs.begin(), songs.end(), songList.begin(), [artistName](const Song& song){
                        return song.m_artist == artistName;
		});

		return songList;
	}


	std::ostream& operator<<(std::ostream& out, const Song& theSong)
	{
		string songYear = "";

		if (theSong.m_year > 0)
		{
			songYear = to_string(theSong.m_year);
		}

		out << "| " << left << setw(20) << theSong.m_title << " | "
			<< left << setw(15) << theSong.m_artist << " | "
			<< left << setw(20) << theSong.m_album << " | "
			<< setw(6) << right << songYear << " | "
			<<  (theSong.lengthOfTheSong % 3600) / 60 << ":" << setw(2) << setfill('0') << theSong.lengthOfTheSong % 60 << " | " 
			<< std::fixed << std::setprecision(2) << theSong.m_price << " |"
			<< setfill(' ');


		return out;
	}
}
