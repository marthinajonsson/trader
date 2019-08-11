//
// Created by mjonsson on 8/8/19.
//

#include <mutex>
#include <iostream>
//#include "IEX.h"
#include "ADX.h"

#include "UniBit.h"

std::mutex single;
static ADX* instance;

ADX& ADX::getInstance()
{
    std::lock_guard<std::mutex> lock(single);
    if(!instance) {
        instance = new ADX();
    }
    return *instance;
}

void ADX::run()
{
    boost::property_tree::ptree response;
    vector<string> result;
    string indicator;
    indicator = indicator.append(UNIBIT::INDICATOR::BASE_REQUEST);
    indicator = indicator.append(UNIBIT::INDICATOR::ADX::KEY_REQUEST_FUNC);
    indicator = indicator.append(UNIBIT::TICKER).append("MSFT.st");

    string key;
    key = key.append(UNIBIT::INDICATOR::DATA_POINT_KEY).append(UNIBIT::INDICATOR::DATA_POINT_VALUE_14);
    key = key.append(UNIBIT::INDICATOR::INTERVAL_KEY).append(UNIBIT::INDICATOR::INTERVAL_MONTH_VALUE);

    response = UNIBIT::fetch(indicator, key);
    UNIBIT::parseArgData(response, result, UNIBIT::INDICATOR::ADX::KEY_RESPONSE::BASE,
            UNIBIT::INDICATOR::ADX::KEY_RESPONSE::CALC);

    double adx = std::stod(result.front());
    result.clear();

//    response = IEX::fetch("MSFT", IEX::INDICATOR::PRICE::CURRENT_PRICE);
//    IEX::parseArgData<double>(response, result, IEX::INDICATOR::PRICE::CURRENT_PRICE);
//    double price = result.front();
//    result.clear();

    if (adx < STRONG_TREND_MIN && adx >= WEAK_TREND_MIN) {
        std::cout << "BAD";
    }
    else if (adx < VERY_STRONG_MIN && adx >= STRONG_TREND_MIN) {
        std::cout << "Good";
    }
    else if (adx < EXTREMLY_STRONG_TREND_MIN && adx >= VERY_STRONG_MIN) {
        std::cout << "Amazing";
    }
    else {
        std::cout << "Unknown";
    }
}
