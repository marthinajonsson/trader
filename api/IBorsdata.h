//
// Created by mjonsson on 4/30/20.
//

#ifndef TRADER_IBORSDATA_H
#define TRADER_IBORSDATA_H

#include <boost/property_tree/ptree.hpp>
#include <Util.h>
#include <boost/property_tree/json_parser.hpp>

class IBorsdata {
public:
    typedef boost::property_tree::ptree ptree;

    void addToken(string &url) {
        ptree JSONconfig;
        string token;
        boost::property_tree::read_json("../data/config.json", JSONconfig);
        auto tokenObj = JSONconfig.get_child("BORSDATA");
        token = tokenObj.get<string>("token", "-");
        if ("-" == token) {
            throw std::logic_error("Unexpected error. Could not find token");
        }
        url.append(ACCESS_KEY);
        url.append(token);
    }

    string getBaseUrl() {
        return BASE_URL_ENDPOINT;
    }
private:
    const string BASE_URL_ENDPOINT = "https://apiservice.borsdata.se/";
    const string ACCESS_KEY = "?authKey=";
};


#endif //TRADER_IBORSDATA_H
