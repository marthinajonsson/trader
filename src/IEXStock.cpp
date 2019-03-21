//
// Created by mjonsson on 1/18/19.
//


#include "IEX.h"

#include <vector>



Json::Value IEX::stock::company(const std::string &symbol)
{
    Json::Value jsonData;

    std::string url(IEX_ENDPOINT);
    url += "/stock/"+symbol+"/company";
    std::cout << "url: " << url << std::endl;
    IEX::sendHttpGetRequest(jsonData, url);
    return jsonData;
}

Json::Value IEX::stock::chart(const std::string &symbol, const std::string& range) {

    Json::Value jsonData;

    std::string url(IEX_ENDPOINT);
    url += "/stock/"+symbol+"/chart/" + range;
    IEX::sendHttpGetRequest(jsonData, url);
    return jsonData;
}


Json::Value IEX::stock::news(const std::string &symbol) {

    Json::Value jsonData;

    std::string url(IEX_ENDPOINT);
    url += "/stock/"+symbol+"/news";
    IEX::sendHttpGetRequest(jsonData, url);
    return jsonData;
}


Json::Value IEX::stock::quote(const std::string &symbol) {

    Json::Value jsonData;

    if(!isValidSymbol(symbol)){
        std::cout << "Invalid Symbol! I am returning an uninitialized JSON object!";
        return jsonData;
    }

    std::string url(IEX_ENDPOINT);
    url += "/stock/"+symbol+"/quote";
    IEX::sendHttpGetRequest(jsonData, url);
    return jsonData;
}

Json::Value IEX::stock::earnings(const std::string &symbol) {

    Json::Value jsonData;

    if(!isValidSymbol(symbol)){
        std::cout << "Invalid Symbol! I am returning an uninitialized JSON object!";
        return jsonData;
    }

    std::string url(IEX_ENDPOINT);
    url += "/stock/"+symbol+"/earnings";
    IEX::sendHttpGetRequest(jsonData, url);
    return jsonData;
}

Json::Value IEX::stock::ohlc(const std::string &symbol) {
    Json::Value jsonData;

    if(!isValidSymbol(symbol)){
        std::cout << "Invalid Symbol! I am returning an uninitialized JSON object!";
        return jsonData;
    }

    std::string url(IEX_ENDPOINT);
    url += "/stock/"+symbol+"/ohlc";
    IEX::sendHttpGetRequest(jsonData, url);
    return jsonData;

}