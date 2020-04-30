//
// Created by mjonsson on 8/17/19.
//

#include "Client.h"

Client* Client::_instance = nullptr;
std::mutex Client::_mx;
std::string Client::buffer = "";

std::size_t Client::callback(void* in, std::size_t size, std::size_t num, std::string* out)
{
    const std::size_t totalBytes(size * num);
    buffer.append((char*)in, totalBytes);
    return totalBytes;
}

void Client::sendRequest(boost::property_tree::ptree &respData, string &url)
{
    CURL* curl = curl_easy_init();
    std::cout << url << std::endl;
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