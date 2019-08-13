//
// Created by mjonsson on 8/6/19.
//

#include <iostream>
#include <string>
#include "Client.h"
#include "UniBit.h"

void UNIBIT::saveData(const string &name, const string& type, vector<std::pair<string, string>>& data)
{
    ptree root;
    ptree arr;
    ptree child1, children, child3;
    string url = "../data/UNIBIT_" + name + ".json";
    vector<std::pair<string,string>>::const_iterator it;
    for (it = data.begin(); it != data.end(); it++) {
        child1.put_value(it->second);
        arr.push_back(std::make_pair(it->first, child1));
    }
    root.add_child(type, arr);

    boost::property_tree::write_json(std::cout, root);
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
    vector<std::pair<string, string>> result = parseArgData(response, UNIBIT::SYMBOLS::KEY_RESPONSE::TICKER,
            UNIBIT::SYMBOLS::KEY_RESPONSE::NAME, UNIBIT::SYMBOLS::KEY_RESPONSE::EXCHANGE_NAME );

    string name = "symbols";
    name.append("[");
    name.append(exchange);
    name.append("]");
    saveData(name, "ticker", result);
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
