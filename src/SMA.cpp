//
// Created by mjonsson on 8/18/19.
//

//
// Created by mjonsson on 8/8/19.
//

#include <mutex>
#include <iostream>
#include "SMA.h"
#include "UniBit.h"
#include "CSVWriter.h"

std::mutex m_sma;
static SMA *instance;

SMA& SMA::getInstance()
{
    std::lock_guard<std::mutex> lock(m_sma);
    if(!instance) {
        instance = new SMA();
    }
    return *instance;
}

void SMA::run()
{
    boost::property_tree::ptree response;
    vector<std::pair<string, string>> result;
    string indicator;
    indicator = indicator.append(UNIBIT::INDICATOR::BASE_REQUEST);
    indicator = indicator.append(UNIBIT::TICKER).append("aapl");
    indicator = indicator.append(UNIBIT::INDICATOR::SMA::KEY_REQUEST_FUNC);

    string key;
    key = key.append(UNIBIT::INDICATOR::DATA_POINT_KEY).append(UNIBIT::INDICATOR::DATA_POINT_VALUE_100);
    key = key.append(UNIBIT::INDICATOR::SERIES_TYPE_KEY).append(UNIBIT::INDICATOR::SERIES_TYPE_VALUE);
    key = key.append(UNIBIT::INDICATOR::INTERVAL_KEY).append(UNIBIT::INDICATOR::INTERVAL_DAILY_VALUE);

    response = UNIBIT::fetch(indicator, key);
    result = UNIBIT::parseArgData(response, UNIBIT::INDICATOR::SMA::KEY_RESPONSE::BASE,
            UNIBIT::INDICATOR::SMA::KEY_RESPONSE::CALC);

    std::string file = "../data/AAPL";
    file.append("_SMA.csv");
    std::vector<std::string> filteredValue;
    for(auto &p : result) {
        filteredValue.emplace_back(p.second);
        std::cout << p.first << " : " << p.second << std::endl;
    }

    save(file, filteredValue);
    result.clear();
    filteredValue.clear();
    notifyObservers(ALGORITHM::SMA);
}
