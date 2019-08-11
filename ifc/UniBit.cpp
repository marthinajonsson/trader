//
// Created by mjonsson on 8/6/19.
//

#include <boost/foreach.hpp>
#include <iostream>
#include <string>
#include "Client.h"
#include "UniBit.h"

void UNIBIT::saveData(const string &name, const string& type, vector<string>& data)
{
    ptree root;
    ptree toBeAdded;
    string url = "../data/UNIBIT_" + name + ".json";
    boost::property_tree::read_json(url, root);
    for (auto &d : data) {
        toBeAdded.put<string>(type,d);
    }

    root.put_child("", toBeAdded);
    boost::property_tree::write_json(url, root, std::locale(), true);
}

void UNIBIT::parseArgData(const ptree &response, vector<string> &argVec, const string& baseArg, const string &arg ...)
{
    string node = response.get<string>(arg, "-");
    if (node == "-") {
        ptree child = response.get_child(baseArg);
        BOOST_ASSERT(!child.empty());
        BOOST_FOREACH(boost::property_tree::ptree::value_type &arr, child) {
            string value = arr.second.get<std::string>(arg);
            argVec.emplace_back(value);
        }
    }else{
        argVec.emplace_back(node);
    }
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
    vector<string> result;
    string url = UNIBIT::BASE_URL_ENDPOINT;
    url.append(UNIBIT::SYMBOLS::BASE_REQUEST);
    url.append(UNIBIT::SYMBOLS::KEY_REQUEST_EXCHANGE);
    url.append(exchange);
    sendRequest(response, url);
    parseArgData(response, result, "", UNIBIT::SYMBOLS::KEY_RESPONSE::TICKER);
    parseArgData(response, result, "", UNIBIT::SYMBOLS::KEY_RESPONSE::NAME);
    parseArgData(response, result, "", UNIBIT::SYMBOLS::KEY_RESPONSE::CURRENCY);
    parseArgData(response, result, "", UNIBIT::SYMBOLS::KEY_RESPONSE::EXCHANGE_NAME);
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
