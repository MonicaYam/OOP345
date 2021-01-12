
// Date of completion:feb 2nd, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#pragma once
#ifndef SDDS_PAIRSUMMABLE_H
#define SDDS_PAIRSUMMABLE_H

#include "Pair.h"
#include <iostream>

namespace sdds
{
    template<typename K, typename V>
    class PairSummable :public Pair<K, V>
    {
    private:
        static V summableValue;
        static size_t _width;

    public:
        static const V& getInitialValue();
        PairSummable() {}
        PairSummable(const K& key, const V& value);
        void display(std::ostream& os) const;
        V sum(const K& key, const V& val) const;
    };


    template<typename K, typename V>
    const V& PairSummable<K, V>::getInitialValue() {
        return summableValue;
    }

    template<typename K, typename V>
    PairSummable<K, V>::PairSummable(const K& key, const V& value) : Pair<K, V>(key, value) {
        size_t tempSize = key.size();

        if (_width < tempSize)
        {
            _width = tempSize;
        }
    }


    template <typename K, typename V>
    size_t PairSummable<K, V>::_width;

    template <typename K, typename V>
    void PairSummable<K, V>::display(std::ostream& os) const {
        os.setf(std::ios::left);
        os.width(_width);

        Pair<K, V>::display(os);

        os.unsetf(std::ios::left);

    }

    template <typename K, typename V>
    V PairSummable<K, V>::sum(const K& key, const V& value) const {
        return (key == this->key())? this->value() + value:value;
    }

    //****************** SPECIALIZATIONS *************************
    //Specialization for string
    template <>
    std::string PairSummable<std::string, std::string>::summableValue = "";

    //Specialization for int
    template <>
    int PairSummable<std::string, int>::summableValue = 0;

    //Specialization for sum function
    template <>
    std::string PairSummable<std::string, std::string>::sum(const std::string& key, const std::string& value) const {
        std::string tempStr ="";
        if (this->key() == key){ 
            if (value == "") {
                tempStr = this->value();
            }
            else {
                tempStr = value + ", " + this->value();
            }
        }
        else {
            tempStr = value;
        }
        return tempStr;
    }

}

#endif
