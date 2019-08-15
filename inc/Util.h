//
// Created by mjonsson on 2/5/19.
//

#ifndef TRADER_UTIL_H
#define TRADER_UTIL_H

#include <boost/array.hpp>
#include <vector>
#include <string>
#include <array>


template<class T, std::size_t S>
using array = std::array<T, S>;

template<class T, std::size_t S>
using array_b = boost::array<T, S>;

template<typename T>
using vector = std::vector<T>;

using string = std::string;

namespace ALGORITHM{
    static const string MEAN_REVERSION = "mean_reversion"; /* what goes up must come down */
    static const string ADX = "adx";
    static const string DEEP_LEARNING = "deeplearning"; /* ta-lib */
}


template<typename T>
void vec_emblace_back(vector<T>& vector, const T& element) {
    if(vector.size() < 180) {
        vector.emplace_back(element);
    }
}

#endif //TRADER_UTIL_H
