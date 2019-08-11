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

static std::mutex _mx1;
static std::mutex _mx2;
std::string buffer;

class Client {
private:
    Client() = default;
    ~Client() = default;
    static Client *_instance;

    const static int HTML_OK = 200;
public:
    static Client& getInstance ()
    {
        std::lock_guard<std::mutex> lock(_mx1);
        if(!_instance) {
            _instance = new Client();
        }
        return *_instance;
    }

    Client(const Client&) = delete;
    Client(Client&&) = delete;
    Client& operator=(const Client&) = delete;
    Client& operator=(Client&&) = delete;

    static std::size_t callback(void* in, std::size_t size, std::size_t num, std::string* out)
    {
        const std::size_t totalBytes(size * num);
        buffer.append((char*)in, totalBytes);
        return totalBytes;
    }

    static void sendHttpGetRequest(boost::property_tree::ptree &respData, string &url)
    {
        std::lock_guard<std::mutex> lock(_mx2);
        CURL* curl = curl_easy_init();

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_IPRESOLVE, CURL_IPRESOLVE_V4);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        long int httpCode(0);
        std::unique_ptr<string> httpData(new string());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, httpData.get());
        curl_easy_perform(curl);
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);
        curl_easy_cleanup(curl);

        if (httpCode != HTML_OK) {
            std::cerr << "HTTP response code: " << httpCode << std::endl;
        }

        std::stringstream response(buffer);
        boost::property_tree::read_json(response, respData);
        buffer = "";
    }
};

#endif //TRADER_CLIENT_H
