//
// Created by mjonsson on 8/6/19.
//

#include <iostream>
#include <string>
#include "Client.h"
#include "UniBit.h"

void UNIBIT::saveSymbolData(const string &name, const string& type, vector<std::pair<string, string>>& data)
{
    ptree root;
    ptree arr;
    ptree ticker;
    ptree company;
    ptree exchange;

    string url = "../data/UNIBIT_" + name + ".json";
    vector<std::pair<string,string>>::const_iterator it;
    string tmp;
    int count = 1;
    for (it = data.begin(); it != data.end(); it++) {
        if (it->first == "ticker") {
            tmp = it->second;
        }
        else if (it->first == "companyName"){
            company.put_value(it->second);
        }
        else if (it->first == "exchange"){
            exchange.put_value(it->second);
        }

        if (0 == count%3) {
            arr.push_back(std::make_pair("company", company));
            arr.push_back(std::make_pair("exchange", exchange));
            ticker.add_child(tmp, arr);
            arr.clear();
        }
        if(!it->second.empty())
            count++;
    }
    root.add_child(type, ticker);
    boost::property_tree::write_json(url, root);
}

void UNIBIT::saveData(const string &name, const string& type, ptree &data, bool clean)
{
    ptree root;
    string url = "../data/UNIBIT_" + name + ".json";
    if(!clean) {
        try{
            boost::property_tree::read_json(url, root);
        }catch(std::exception &){

        }
    }
    root.add_child(type, data);
    boost::property_tree::write_json(url, root);
}

UNIBIT::ptree UNIBIT::fetch(const string &indicator, const string &key)
{
    ptree jsonData;
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
    UNIBIT::ptree response;
    string url = UNIBIT::BASE_URL_ENDPOINT;
    url.append(UNIBIT::SYMBOLS::BASE_REQUEST);
    url.append(UNIBIT::SYMBOLS::KEY_REQUEST_EXCHANGE);
    url.append(exchange);

    sendRequest(response, url);

    string name = "symbols";
    name.append("[");
    name.append(exchange);
    name.append("]");

    saveData(name, "ticker", response);
}

void UNIBIT::addToken(string &url)
{
    UNIBIT::ptree JSONconfig;
    string token;
    boost::property_tree::read_json("../data/config.json", JSONconfig);
    auto tokenObj = JSONconfig.get_child("UNIBIT");
    token = tokenObj.get<string>("token", "-");
    if ("-" == token) {
        throw std::logic_error("Unexpected error. Could not find token");
    }
    url.append(UNIBIT::ACCESS_KEY);
    url.append(token);
}

void UNIBIT::sendRequest(UNIBIT::ptree &respData, string &url)
{
    addToken(url);
    Client::sendHttpGetRequest(respData, url);
}
