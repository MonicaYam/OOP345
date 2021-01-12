
// Date of completion:January 27th, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.


#ifndef SDDS_RECORDSET_H
#define SDDS_RECORDSET_H

#include <string>

namespace sdds{
    class RecordSet{
        std::string* s;
        size_t _strSize = 0;


        public:
        RecordSet();
        ~RecordSet();
        RecordSet(const char*); // read file and load strings from the file to string variable
        RecordSet(const RecordSet&); //Copy Constructor
        RecordSet(RecordSet&&);
        size_t size();
        std::string getRecord(size_t num);

        RecordSet& operator=(const RecordSet&); //copy assigment
	RecordSet& operator=(RecordSet&&); //move assigment
    };
}

#endif
