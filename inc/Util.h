//
// Created by mjonsson on 2/5/19.
//

#ifndef TRADER_UTIL_H
#define TRADER_UTIL_H


#include <vector>
#include <string>

static const std::string MEAN_REVERSION = "mean_reversion"; /* what goes up must come down */
static const std::string SENTIMENT = "sentiment"; /* buy the rumor, sell the news*/
static const std::string MOMENTUM = "momentum"; /* the trend is your friend */
static const std::string SEASONALITY = "seasonality"; /* sell in May and go away */
static const std::string DEEP_LEARNING = "deeplearning"; /* ta-lib */


template<typename T>
void vec_emblace_back(std::vector<T>& vector, const T& element) {
    if(vector.size() < 180) {
        vector.emplace_back(element);
    }
}

#endif //TRADER_UTIL_H
