//
// Created by mjonsson on 8/5/19.
//

#ifndef TRADER_CLIENT_H
#define TRADER_CLIENT_H


#include <jsoncpp/json/json.h>
#include <curl/curl.h>
#include <iostream>
#include <fstream>
#include <memory>
#include "Util.h"

class Client {
private:
    const static int HTML_OK = 200;
public:

    Client() = default;
    ~Client() = default;

    Client(const Client&) = delete;
    Client(Client&&) = delete;
    Client& operator=(const Client&) = delete;
    Client& operator=(Client&&) = delete;

    static std::size_t callback(const char *in, std::size_t size, std::size_t num, string *out) {
        const std::size_t totalBytes(size * num);
        out->append(in, totalBytes);
        return totalBytes;
    }

    static void sendHttpGetRequest(Json::Value &jsonData, string &url)
    {
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

        Json::CharReaderBuilder builder;
        Json::CharReader * reader = builder.newCharReader();
        string errors;

        bool result = reader->parse(httpData.get()->c_str(), httpData->end().base(), &jsonData, &errors);

        if (!result) {
            std::cout << "False curl request: " << url << std::endl;
        }
        delete reader;
    }
};

#endif //TRADER_CLIENT_H
