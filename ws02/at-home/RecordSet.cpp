
// Date of completion:January 27th, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream> //or istream
#include <fstream>


#include "RecordSet.h"
#include "RecordSet.h"

using namespace std;

namespace sdds {
    RecordSet::RecordSet(){
        s = nullptr;
    }
    RecordSet::~RecordSet(){
        if (s) {
            delete[] s;
        }
    }

    RecordSet::RecordSet(const RecordSet& src){
        if (this != &src) {

            _strSize = src._strSize;
            s = new string[_strSize];
            for(size_t i = 0; i < _strSize; ++i){
                s[i] = src.s[i];
            }
        }else{
	  s = nullptr;
	}
    }

    //read file
    RecordSet::RecordSet(const char* filename){
        s = nullptr;

        string tempStr;
        char delim = ' ';

        ifstream ifs(filename);

        if(ifs){
           while(getline(ifs, tempStr,delim)){
                ++_strSize;
            }

           ifs.clear();
           ifs.seekg(0, ios_base::beg);
           s = new string[_strSize];
           size_t i = 0;
           while (getline(ifs, tempStr, delim)) {
               s[i] = tempStr;
               i++;
           }

        }
    }

    RecordSet::RecordSet(RecordSet&& src){
        if (this != &src) {
            _strSize = src._strSize;
            s = new string[_strSize];
            for(size_t i = 0; i < _strSize; ++i){
                s[i] = src.s[i];
            }
	    src.s = nullptr;
        }else{
	  s = nullptr;
	}
    }

    string RecordSet::getRecord(size_t num){
        string tempStr = "";
        if(num >= 0 && num < _strSize){
            if (s) {
                tempStr = s[num];
            }
        }
        else {
            tempStr = "";
        }

        return tempStr;
    }

    size_t RecordSet::size(){
        return _strSize;
    }

    RecordSet& RecordSet::operator=(const RecordSet& src) {
        if (this != &src) {

            _strSize = src._strSize;
            s = new string[_strSize];
            for (size_t i = 0; i < _strSize; ++i) {
                s[i] = src.s[i];
            }
        }else{
	  s = nullptr;
	}
        return *this;
    }

   RecordSet& RecordSet::operator=(RecordSet&& src){
        if (this != &src) {
            _strSize = src._strSize;
            s = new string[_strSize];
            for (size_t i = 0; i < _strSize; ++i) {
                s[i] = src.s[i];
            }

	    src.s = nullptr;
        }
        return *this;	

   }
}
