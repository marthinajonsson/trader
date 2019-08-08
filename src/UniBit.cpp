//
// Created by mjonsson on 8/6/19.
//

#include <iostream>
#include <fstream>
#include <string>
#include <Client.h>
#include "UniBit.h"

template<typename T>
void UNIBIT::saveData(const string &name, const string& type, vector<T>& data)
{
    Json::Value root;
    Json::Value add;
    string url = "../data/UNIBIT_" + name + ".json";

    add[type].append(Json::arrayValue);
    int index = 0;
    for(const string &s : data) {
        add[type][index] = s;
        index++;
    }
    root.append(add);
    std::ofstream db_write;
    db_write.open(url, std::ios::trunc);
    db_write << root;
    db_write.close();
}

template<typename T>
void UNIBIT::parseArgData(const Json::Value &response, vector<T> &argVec, const string& baseArg, const string &arg)
{
    if (!response.isMember(arg)) {
        std::cout << "Key doesn't exists" << std::endl;
        return;
    }

    auto val = response[arg];
    if (val.isArray()) {
        for (const auto &v : val) {
            argVec.emplace_back(v.asString());
        }
    }
    else {
        argVec.emplace_back(val.asString());
    }
}

Json::Value UNIBIT::fetch(const string &symbol, const string &indicator, const string &key)
{
    Json::Value jsonData;
    string url(BASE_URL_ENDPOINT);
    url = url.append(indicator);
    if (!key.empty()) {
        url = url.append("/").append(key);
    }
    addToken(url);
    sendRequest(jsonData, url);
    return jsonData;
}

void UNIBIT::updateReferenceList(const string& exchange)
{
    Json::Value response;
    vector<string> result;
    string url = UNIBIT::BASE_URL_ENDPOINT;
    url.append(UNIBIT::SYMBOLS::BASE_REQUEST);
    url.append(UNIBIT::SYMBOLS::KEY_REQUEST_EXCHANGE);
    url.append(exchange);
    sendRequest(response, url);
    parseArgData(response, result, "", UNIBIT::SYMBOLS::KEY_RESPONSE::TICKER);
    parseArgData(response, result, "", UNIBIT::SYMBOLS::KEY_RESPONSE::CURRENCY);
    string name = "symbols";
    name.append("[");
    name.append(exchange);
    name.append("]");
    saveData(name, "ticker", result);
}

void UNIBIT::addToken(string &url)
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
        token = UNIBIT::ACCESS_KEY + JSONconfig["UNIBIT"]["token"].asString();
    }
    url.append(token);
}

void UNIBIT::sendRequest(Json::Value &jsonData, string &url)
{
    Client client;
    addToken(url);
    client.sendHttpGetRequest(jsonData, url);
}
