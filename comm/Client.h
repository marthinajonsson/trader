//
// Created by mjonsson on 8/5/19.
//

#ifndef TRADER_CLIENT_H
#define TRADER_CLIENT_H

#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <curl/curl.h>
#include <iostream>
#include <fstream>
#include <memory>
#include <mutex>
#include "Util.h"

class Client {
private:
    Client() = default;

    ~Client() = default;

    static Client *_instance;
    static std::mutex _mx;
    static std::string buffer;
    static const int HTML_OK = 200;
public:
    static Client &getInstance() {
        std::lock_guard<std::mutex> lock(_mx);
        if (!_instance) {
            _instance = new Client();
        }
        return *_instance;
    }

    Client(const Client &) = delete;

    Client(Client &&) = delete;

    Client &operator=(const Client &) = delete;

    Client &operator=(Client &&) = delete;

    static std::size_t callback(void *in, std::size_t size, std::size_t num, std::string *out);

    static void sendRequest(boost::property_tree::ptree &respData, string &url);
};

#endif //TRADER_CLIENT_H
