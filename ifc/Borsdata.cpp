//
// Created by mjonsson on 4/19/20.
//

#include "Borsdata.h"
#include "Client.h"
using namespace Comm;


void BORSDATA::addToken(string &url)
{
    BORSDATA::ptree JSONconfig;
    string token;
    boost::property_tree::read_json("../data/config.json", JSONconfig);
    auto tokenObj = JSONconfig.get_child("BORSDATA");
    token = tokenObj.get<string>("token", "-");
    if ("-" == token) {
        throw std::logic_error("Unexpected error. Could not find token");
    }
    url.append(BORSDATA::ACCESS_KEY);
    url.append(token);
}

void BORSDATA::sendRequest(BORSDATA::ptree &respData, string &url)
{
    addToken(url);
    Client::getInstance().sendRequest(respData, url);
}
