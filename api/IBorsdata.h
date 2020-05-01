//
// Created by mjonsson on 4/30/20.
//

#ifndef TRADER_IBORSDATA_H
#define TRADER_IBORSDATA_H

#include <boost/property_tree/ptree.hpp>
#include <Util.h>
#include <boost/property_tree/json_parser.hpp>
#include <ApiConfiguration.h>

class IBorsdata {
public:
    typedef boost::property_tree::ptree ptree;

    void addToken(string &url) {
        string token = ApiConfiguration::getToken();
        url.append(ACCESS_KEY);
        url.append(token);
    }

    string getBaseUrl() {
        return BASE_URL_ENDPOINT;
    }
private:
    const string BASE_URL_ENDPOINT = ApiConfiguration::getBase();
    const string ACCESS_KEY = "?authKey=";
};


#endif //TRADER_IBORSDATA_H
