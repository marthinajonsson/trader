//
// Created by mjonsson on 1/11/19.
//

//#include "Client.h"
#include "IEX.h"
#include "main.h"

void IEX::saveData(const string &name, const string& type, vector<string>& data) {
    Json::Value root;
    Json::Value add;
    string url = "../data/IEX_" + name + ".json";

    add[type].append(Json::arrayValue);
    int index = 0;
    for(const auto &s : data) {
        add[type][index] = s;
        index++;
    }
    root.append(add);
    std::ofstream db_write;
    db_write.open(url, std::ios::trunc);
    db_write << root;
    db_write.close();
}

void IEX::parseDataList(const string &type, const Json::Value &response, vector<string> &result)
{
    for(const auto &data : response)
        result.emplace_back(data[type].asString());
}

void IEX::parseArgData(const Json::Value &response, vector<string> &result, const string &arg)
{
   if (!response.isMember(arg)) {
        std::cout << "Key doesn't exists" << std::endl;
        return;
    }

    auto val = response[arg];
    if (val.isArray()) {
        for (const auto &v : val)
            result.emplace_back(v.asString());
    }
    else {
        result.emplace_back(val.asString());
    }
}

void IEX::parseLocalSymbol(const Json::Value &response, vector<string> &result)
{
    int j = 0;
    for(const auto & data : response) {
        while(j < data["symbol"].size()) {
            result.emplace_back(data["symbol"][j].asString());
            j++;
        }
    }
}

vector<string> IEX::getSymbolList(const string &region)
{
    Json::Value root;
    vector<string> list;
    string url = "../data/symbols";
    url = url.append("[");
    url = url.append(region);
    url = url.append("]");
    std::ifstream db_read(url, std::ifstream::binary);
    db_read >> root;
    db_read.close();
    parseLocalSymbol(root, list);
    return list;
}

bool IEX::isValidSymbol(const string &symbol) {
    vector<string> symbolList = getSymbolList("us");
    string symbolCopy = symbol;
    boost::to_upper(symbolCopy);
    return std::find(symbolList.begin(), symbolList.end(), symbolCopy) != symbolList.end();
}

Json::Value IEX::fetch(const string &symbol, const string &indicator, const string& filterKey)
{
    Json::Value jsonData;
    if (!isValidSymbol(symbol)) {
        std::cout << "Invalid Symbol! I am returning an uninitialized JSON object!";
        return jsonData;
    }

    string url(BASE_URL_ENDPOINT);
    url = url.append("/stock/").append(symbol).append("/").append(indicator);
    if (!filterKey.empty()) {
        url = url.append("/").append(filterKey);
    }
    addToken(url);
    sendRequest(jsonData, url);
    return jsonData;
}

void IEX::updateReferenceList(const string &region) {
    Json::Value jsonData;
    string url(BASE_URL_ENDPOINT);
    vector<string> list;
    url = url.append("/ref-data/region/").append(region).append("/symbols");
    addToken(url);
    IEX::sendRequest(jsonData, url);
    assert(jsonData.isArray());
    parseDataList("symbol", jsonData, list);
    string name = "symbols";
    name.append("[");
    name.append(region);
    name.append("]");
    saveData("symbols["+region+"]", "symbols:"+region, list);
}

void IEX::addToken(string &url)
{
    Json::Value JSONconfig;
    string token;
    std::ifstream config("../data/config.json", std::ifstream::binary);
    if (!config.is_open()) {
        std::cerr << "token is missing, could not find config.json" << std::endl;
        return;
    }
    else {
        config >> JSONconfig;
        config.close();
        token = "?token=" + JSONconfig["IEX"]["token"].asString();
    }
    url = url.append(token);
}

void IEX::sendRequest(Json::Value &jsonData, string &url)
{
    addToken(url);
   // Client::sendHttpGetRequest(jsonData, url);
}
