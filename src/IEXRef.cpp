//
// Created by mjonsson on 1/19/19.
//
#include "IEX.h"

#include <vector>

void IEX::ref::parseSymbolData(const Json::Value &IEXdata, std::vector<std::string> &symbolVec)
{
    int i = 0;
    while(i < IEXdata.size()) {
        symbolVec.push_back(IEXdata[i]["symbol"].asString());
        i++;
    }
}

Json::Value IEX::ref::dividend(const std::string &symbol)
{
    Json::Value jsonData;
    std::string url(IEX_ENDPOINT);
    url += "/ref-data/daily-list/dividends";
    IEX::sendHttpGetRequest(jsonData, url);
    return jsonData;
}

std::vector<std::string> IEX::ref::getSymbolList()
{
    Json::Value jsonData;
    std::string url(IEX_ENDPOINT);
    std::vector<std::string> symbolList;
    url += "/ref-data/symbols";
    IEX::sendHttpGetRequest(jsonData, url);
    assert(jsonData.isArray());
    parseSymbolData(jsonData, symbolList);
    return symbolList;
}