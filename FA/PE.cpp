//
// Created by mjonsson on 10/12/19.
//

#include "PE.h"

#include <mutex>
#include <iostream>
#include <boost/property_tree/ptree.hpp>
#include "Interests.h"

std::mutex m_pe;
static PE *instance;

PE& PE::getInstance()
{
    std::lock_guard<std::mutex> lock(m_pe);
    if(!instance) {
        instance = new PE();
    }
    return *instance;
}

void PE::run()
{
    boost::property_tree::ptree response;
    vector<std::pair<string, string>> result;

    Interests interests;
    vector<string> stocks = interests.getInterests();
    for (const string& s : stocks) {
        string indicator;
        string key;

//        response = UNIBIT::fetch(indicator, key);
//        result = UNIBIT::parseArgData(response, UNIBIT::INDICATOR::RSI::KEY_RESPONSE::BASE,
//                                      UNIBIT::INDICATOR::RSI::KEY_RESPONSE::CALC);

        std::string file = "../data/";
        file.append(s);
        file.append("_PE.csv");
        std::vector<std::string> filteredValue;
        int odd = 0;
        for(auto &p : result) {
            filteredValue.emplace_back(p.second);
        }
        save(file, filteredValue);
        filteredValue.clear();
        result.clear();
    }
    notifyObservers(ALGORITHM::PE);
}
