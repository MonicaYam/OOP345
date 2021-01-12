#ifndef SDDS_RECORDSET_H
#define SDDS_RECORDSET_H

#include <string>

namespace sdds{
    class RecordSet{
        std::string* s;
        int _strSize = 0;


        public:
        RecordSet();
        ~RecordSet();
        RecordSet(const char*); // read file and load strings from the file to string variable
        RecordSet(const RecordSet&); //Copy Constructor
        size_t size();
        std::string getRecord(int num);

        RecordSet& operator=(const RecordSet&); //copy assigment
    };
}

#endif
