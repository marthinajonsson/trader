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
    void parseData(const Json::Value &IEXdata, std::vector<std::string> &argVec);
    void parseArgData(const Json::Value &IEXdata, std::vector<std::string> &argVec, std::string &&arg);

    bool isValidSymbol(const std::string &);

    namespace ref {
        void parseSymbolData(const Json::Value &, std::vector<std::string> &);
        std::vector<std::string> avaliableSymbols();
    }

    namespace stock {
        Json::Value company(const std::string &symbol);
        Json::Value quote(const std::string &symbol);
        Json::Value earnings(const std::string &symbol);

    }
}

#endif //TRADER_IEX_H
