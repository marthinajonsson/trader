//
// Created by mjonsson on 1/11/19.
//

#ifndef TRADER_IEX_H
#define TRADER_IEX_H

#include <json/json.h>
#include <curl/curl.h>
#include <locale> //std::locale, std::isdigit
#include <string>
#include <cassert>
#include <iostream>
#include <vector>
#include <algorithm>
#include <boost/algorithm/string.hpp>

#define IEX_ENDPOINT "https://api.iextrading.com/1.0"

namespace IEX {

    void sendHttpGetRequest(Json::Value &jsonData, const std::string url);
    void parseSymbolData(const Json::Value &, std::vector<std::string> &);
    void parseArgData(const Json::Value &IEXdata, std::vector<std::string> &argVec, std::string &&arg);
    bool isValidSymbol(const std::string &);
    std::vector<std::string> getSymbolList();

    namespace stock {
        Json::Value company(const std::string &symbol);
    }
}

#endif //TRADER_IEX_H
