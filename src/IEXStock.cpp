//
// Created by mjonsson on 1/18/19.
//


#include "IEX.h"

Json::Value IEX::stock::fetch(const string &symbol, const string &indicator, const string& filterKey){

    Json::Value jsonData;
    if (!isValidSymbol(symbol)) {
        std::cout << "Invalid Symbol! I am returning an uninitialized JSON object!";
        return jsonData;
    }

    string url(IEX_ENDPOINT);
    url = url.append("/stock/").append(symbol).append("/").append(indicator);
    if (!filterKey.empty()) {
        url = url.append("/").append(filterKey);
    }
    IEX::sendHttpGetRequest(jsonData, url);
    return jsonData;
}


Json::Value IEX::stock::company(const string &symbol)
{
    Json::Value jsonData;
    string url(IEX_ENDPOINT);
    url = url.append("/stock/").append(symbol).append("/company");
    std::cout << "url: " << url << std::endl;
    IEX::sendHttpGetRequest(jsonData, url);
    return jsonData;
}

