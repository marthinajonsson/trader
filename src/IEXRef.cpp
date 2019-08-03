//
// Created by mjonsson on 1/19/19.
//
#include "IEX.h"

#include <unordered_set>
#include <fstream>

void saveData(const string &name, const string& type, vector<string>& data) {
    Json::Value root;
    Json::Value add;
    string url = "../data/" + name + ".json";
    if(name != "symbols") {
        std::ifstream db_read(url, std::ifstream::binary);
        db_read >> root;
        db_read.close();
    }

    add[type].append(Json::arrayValue);
    int index = 0;
    for(const string &s : data) {
        add[type][index] = s;
        index++;

    }
    root.append(add);
    std::ofstream db_write(url, std::ios::trunc);
    db_write << root;
    db_write.close();
}

void IEX::ref::parseDataList(const string &type, const Json::Value &IEXdata, vector<string> &vec)
{
    for(const auto & data : IEXdata) {
        vec.emplace_back(data[type].asString());
    }
}

void IEX::ref::parseDataListSorted(const string &type, const Json::Value &IEXdata, vector<string> &vec)
{
    parseDataList(type, IEXdata, vec);
    std::sort(vec.begin(), vec.end());
    vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
}

void IEX::ref::parseLocalSymbol(const Json::Value &IEXdata, vector<string> &symbolVec)
{
    int j = 0;
    for(const auto & data : IEXdata) {
        while(j < data["symbol"].size()) {
            symbolVec.emplace_back(data["symbol"][j].asString());
            j++;
        }
    }
}

Json::Value IEX::ref::getISINList()
{
    Json::Value jsonData;
    vector<string> list;
    string url(IEX_ENDPOINT);
    url = url.append("/ref-data/isin");
    IEX::sendHttpGetRequest(jsonData, url);
    assert(jsonData.isArray());
    saveData("isins", "isin", list);
    return jsonData;
}

vector<string> IEX::ref::updateSymbolList()
{
    Json::Value jsonData;
    string url(IEX_ENDPOINT);
    vector<string> list;
    url = url.append("/ref-data/symbols");
    IEX::sendHttpGetRequest(jsonData, url);
    assert(jsonData.isArray());
    parseDataList("symbol", jsonData, list);
    saveData("symbols", "symbol", list);
    return list;
}

vector<string> IEX::ref::updateRegionList()
{
    Json::Value jsonData;
    string url(IEX_ENDPOINT);
    vector<string> list;
    url = url.append("/ref-data/exchanges");
    IEX::sendHttpGetRequest(jsonData, url);
    assert(jsonData.isArray());
    parseDataListSorted("region", jsonData, list);
    saveData("regions", "region", list);
    return list;
}

vector<string> IEX::ref::getSymbolList()
{
    Json::Value root;
    vector<string> list;
    string url = "../data/symbols.json";
    std::ifstream db_read(url, std::ifstream::binary);
    db_read >> root;
    db_read.close();
    parseLocalSymbol(root, list);
    return list;
}

std::vector<std::string> IEX::ref::getRegionList()
{
    Json::Value root;
    vector<string> list;
    string url = "../data/regions.json";
    std::ifstream db_read(url, std::ifstream::binary);
    db_read >> root;
    db_read.close();
    parseDataList("symbol", root, list);
    return list;
}

std::vector<std::string> IEX::ref::getSymbolListByRegion(std::string &&region) {
    Json::Value jsonData;
    string url(IEX_ENDPOINT);
    vector<string> list;
    url = url.append("/ref-data/region/").append(region).append("/symbols");
    IEX::sendHttpGetRequest(jsonData, url);
    assert(jsonData.isArray());
    parseDataList("symbol", jsonData, list);
    saveData("regions", "symbols:"+region, list);
    return list;
}
