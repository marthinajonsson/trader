//
// Created by mjonsson on 8/8/19.
//

#include <mutex>
#include <iostream>
#include "ADX.h"
#include "UniBit.h"

std::mutex m_adx;
static ADX *instance;

ADX& ADX::getInstance()
{
    std::lock_guard<std::mutex> lock(m_adx);
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
    indicator = indicator.append(UNIBIT::TICKER).append("nvda");
    indicator = indicator.append(UNIBIT::INDICATOR::ADX::KEY_REQUEST_FUNC);

    string key;
    key = key.append(UNIBIT::INDICATOR::DATA_POINT_KEY).append(UNIBIT::INDICATOR::DATA_POINT_VALUE_50);
    key = key.append(UNIBIT::INDICATOR::INTERVAL_KEY).append(UNIBIT::INDICATOR::INTERVAL_DAILY_VALUE);

    response = UNIBIT::fetch(indicator, key);

    result = UNIBIT::parseArgData(response, UNIBIT::INDICATOR::ADX::KEY_RESPONSE::BASE,
            UNIBIT::INDICATOR::ADX::KEY_RESPONSE::CALC);

    std::string file = "NVDA";
    file.append("_ADX.csv");
    std::vector<std::string> filteredValue;
    int odd = 0;
    for(auto &p : result) {
        filteredValue.emplace_back(p.second);
    }

    save(file, filteredValue);
    filteredValue.clear();
    result.clear();
    notifyObservers(ALGORITHM::ADX);
}
