//
// Created by mjonsson on 2/5/19.
//

#ifndef TRADER_UTIL_H
#define TRADER_UTIL_H


#include <vector>

template<typename T>
void vec_emblace_back(std::vector<T>& vector, const T& element) {
    if(vector.size() < 180) {
        vector.emplace_back(element);
    }
}

#endif //TRADER_UTIL_H
