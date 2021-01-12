#ifndef SDDS_PAIR_H
#define SDDS_PAIR_H

#include <iostream>

namespace sdds{
    template<typename K, typename V>
    class Pair{
        K pairKey;
        V pairValue;
        public:
        Pair():pairKey(), pairValue(){};
        //: copies the values received in the parameters into instance variables
        Pair(const K& key, const V& value): pairKey(key), pairValue(value){}

        //: returns the key component of the pair
        const K& key() const{
            return pairKey;
        }

        //: returns the value component of the pair
        const V& value() const{
            return pairValue;
        }

        //: inserts into the parameter the key and value of the pair in the following format 
        void display(std::ostream& os) const{
            os << key() << " : " << value() << std::endl;
        }
    };

    //: calls the function Pair<L, V>::display() to insert a pair into the stream.
    template<typename K, typename V>
    std::ostream& operator<<(std::ostream& os, const Pair<K, V>& pair){
        pair.display(os);
        return os;
    }
}
#endif
