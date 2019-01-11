//
// Created by mjonsson on 1/11/19.
//

#ifndef TRADER_IEX_H
#define TRADER_IEX_H

#include <json/json.h>
#include <curl/curl.h>

#define IEX_ENDPOINT "https://api.iextrading.com/1.0"

namespace IEX {

    void sendRequest(Json::Value &jsonData, const std::string url);
    void parseSymbolData(const Json::Value &, std::vector<std::string> &);

    bool isValidSymbol(const std::string &);
    std::vector<std::string> getSymbolList();


    namespace stock{

        namespace symbol {

        }

        namespace market{
            Json::Value today_earnings;

        }

    }
}

#endif //TRADER_IEX_H
