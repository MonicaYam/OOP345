
// Date of completion:feb 2nd, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#pragma once
#ifndef SDDS_SET_H
#define SDDS_SET_H


namespace sdds
{
    template<typename T, size_t N>
    class Set
    {
        size_t arrayIdx = 0;
        T array[N];

    public:
        //: returns the number of elements in the set
        size_t size() const {
            return arrayIdx;
        }

        //: returns the element at index i (assume the parameter is valid).
        const T& operator[](size_t idx) const {
            return array[idx];
        }

        //: if the set didn't reach the capacity, add a copy of the parameter to the array. Otherwise, do nothing.
        void operator+=(const T& item) {
            if (arrayIdx < N) {
                array[arrayIdx++] = item;
            }
        }
    };
}
#endif
