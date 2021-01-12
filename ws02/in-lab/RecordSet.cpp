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
        s = nullptr;
        if (this != &src) {

            _strSize = src._strSize;
            s = new string[_strSize];
            for(int i = 0; i < _strSize; ++i){
                s[i] = src.s[i];
            }
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
           int i = 0;
           while (getline(ifs, tempStr, delim)) {
               s[i] = tempStr;
               i++;
           }

        }
    }

    string RecordSet::getRecord(int num){
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

        s = nullptr;
        if (this != &src) {

            _strSize = src._strSize;
            s = new string[_strSize];
            for (int i = 0; i < _strSize; ++i) {
                s[i] = src.s[i];
            }
        }
        return *this;
    }
}
