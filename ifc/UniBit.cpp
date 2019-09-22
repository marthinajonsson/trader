//
// Created by mjonsson on 8/6/19.
//

#include <iostream>
#include <string>
#include <JsonWriter.h>
#include "Client.h"
#include "UniBit.h"

using namespace HTTP;

UNIBIT::ptree UNIBIT::fetch(const string &indicator, const string &key)
{
    ptree jsonData;
    string url(BASE_URL_ENDPOINT);
    url = url.append(indicator);
    if (!key.empty()) {
        url = url.append("").append(key);
    }
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

    IO::JsonWriter::getInstance().addPropertyTree("UNIBIT", name, "ticker", response);
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
    Client::getInstance().sendRequest(respData, url);
}
