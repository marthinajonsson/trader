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
    vector<std::pair<string, string>> result;
    string indicator;
    indicator = indicator.append(UNIBIT::INDICATOR::BASE_REQUEST);
    indicator = indicator.append(UNIBIT::INDICATOR::ADX::KEY_REQUEST_FUNC);
    indicator = indicator.append(UNIBIT::TICKER).append("MSFT.st");

    string key;
    key = key.append(UNIBIT::INDICATOR::DATA_POINT_KEY).append(UNIBIT::INDICATOR::DATA_POINT_VALUE_14);
    key = key.append(UNIBIT::INDICATOR::INTERVAL_KEY).append(UNIBIT::INDICATOR::INTERVAL_MONTH_VALUE);

    response = UNIBIT::fetch(indicator, key);
//    result = UNIBIT::parseArgData(response, UNIBIT::INDICATOR::ADX::KEY_RESPONSE::BASE,
//            UNIBIT::INDICATOR::ADX::KEY_RESPONSE::CALC);

//    double adx = std::stod(result.front().second);
    result.clear();

//    response = IEX::fetch("MSFT", IEX::INDICATOR::PRICE::CURRENT_PRICE);
//    IEX::parseArgData<double>(response, result, IEX::INDICATOR::PRICE::CURRENT_PRICE);
//    double price = result.front();
//    result.clear();

//    }
}
