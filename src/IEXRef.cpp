//
// Created by mjonsson on 1/19/19.
//
#include "IEX.h"

#include <unordered_set>
#include <vector>
#include <fstream>

void saveData(const std::string &name, const std::string& type, std::vector<std::string>& data) {
    Json::Value root;
    Json::Value add;
    std::string url = "../data/" + name + ".json";
    if(name != "symbols") {
        std::ifstream db_read(url, std::ifstream::binary);
        db_read >> root;
        db_read.close();
    }

    add[type].append(Json::arrayValue);
    int index = 0;
    for(const std::string &s : data) {
        add[type][index] = s;
        index++;

    }
    root.append(add);
    std::ofstream db_write(url, std::ios::trunc);
    db_write << root;
    db_write.close();
}

void IEX::ref::parseSymbolData(const Json::Value &IEXdata, std::vector<std::string> &symbolVec)
{
    int i = 0;
    while(i < IEXdata.size()) {
        symbolVec.push_back(IEXdata[i]["symbol"].asString());
        i++;
    }
}

void IEX::ref::parseSymbolDataByArg(const Json::Value &IEXdata, std::vector<std::string> &symbolVec, const std::string &arg)
{
    int i = 0;
    while(i < IEXdata.size()) {
        symbolVec.push_back(IEXdata[i][arg].asString());
        i++;
    }
    std::sort(symbolVec.begin(), symbolVec.end());
    symbolVec.erase(std::unique(symbolVec.begin(), symbolVec.end()), symbolVec.end());
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
    saveData("symbols", "symbol", symbolList);
    return symbolList;
}

std::vector<std::string> IEX::ref::getRegionList()
{
    Json::Value jsonData;
    std::string url(IEX_ENDPOINT);
    std::vector<std::string> symbolList;
    url += "/ref-data/exchanges";
    IEX::sendHttpGetRequest(jsonData, url);
    assert(jsonData.isArray());
    parseSymbolDataByArg(jsonData, symbolList, "region");
    saveData("regions", "region", symbolList);
    return symbolList;
}

std::vector<std::string> IEX::ref::getSymbolListByRegion(std::string &&region) {
    Json::Value jsonData;
    std::string url(IEX_ENDPOINT);
    std::vector<std::string> symbolList;
    url += "/ref-data/region/";
    url += region;
    url += "/symbols";
    IEX::sendHttpGetRequest(jsonData, url);
    assert(jsonData.isArray());
    parseSymbolData(jsonData, symbolList);
    saveData("regions", "symbols:"+region, symbolList);
    return symbolList;
}
