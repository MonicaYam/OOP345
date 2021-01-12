
// Date of completion:feb 2nd, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#pragma once
#ifndef SDDS_SETSUMMABLE_H
#define SDDS_SETSUMMABLE_H

#include "Set.h"

namespace sdds
{
    template<typename T, size_t N, typename K, typename V>
    class SetSummable :public Set<T, N>
    {

    public:
        //this function accumulates all the values stored in the collection that have the key key into a local object of type V.
        V accumulate(const K& key) const {
            V accumulator = T::getInitialValue();

            for (size_t i = 0; i <= this ->size(); ++i) {
                if (key == ((Set<T, N>&)* this)[i].key()) {
                    accumulator = ((Set<T, N>&) * this)[i].sum(key, accumulator);
                }
            }

            return accumulator;
        }
    };

}
#endif
