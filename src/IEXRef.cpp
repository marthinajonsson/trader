//
// Created by mjonsson on 1/19/19.
//
#include "IEX.h"

#include <vector>

void IEX::ref::parseSymbolData(const Json::Value &IEXdata, std::vector<std::string> &symbolVec)
{
    int i = 0;
    //Step through JSON file until the end is reached
    while(i < IEXdata.size()) {
        symbolVec.push_back(IEXdata[i]["symbol"].asString());
        i++;
    }
}

std::vector<std::string> IEX::ref::symbols()
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