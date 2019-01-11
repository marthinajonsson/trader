//
// Created by mjonsson on 1/11/19.
//

#include "IEX.h"


#include <boost/algorithm/string.hpp>
#include <vector>
#include <assert.h>
#include <algorithm>
#include <memory>


std::vector<std::string> IEX::getSymbolList()
{
    Json::Value jsonData;
    std::string url(IEX_ENDPOINT);
    std::vector<std::string> symbolList;
    url += "/ref-data/symbols";
    IEX::sendRequest(jsonData, url);
    assert(jsonData.isArray()); //Crash if not an array
    parseSymbolData(jsonData, symbolList);
    return symbolList;

}

bool IEX::isValidSymbol(const std::string &symbol)
{
    std::vector<std::string> symbolList = getSymbolList();
    std::string symbolCopy = symbol;
    boost::to_upper(symbolCopy);
    return std::find(symbolList.begin(), symbolList.end(), symbolCopy) != symbolList.end();
}

std::size_t callback(const char* in, std::size_t size, std::size_t num, std::string* out)
{
    const std::size_t totalBytes(size * num);
    out->append(in, totalBytes);
    return totalBytes;
}

void IEX::sendRequest(Json::Value &jsonData, const std::string url)
{
    CURL* curl = curl_easy_init();

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_IPRESOLVE, CURL_IPRESOLVE_V4);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    long int httpCode(0);
    std::unique_ptr<std::string> httpData(new std::string());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, httpData.get());
    curl_easy_perform(curl);
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);
    curl_easy_cleanup(curl);

    Json::Reader jsonReader;
    bool result = jsonReader.parse(*httpData, jsonData);
    assert(result);
}

void IEX::parseSymbolData(const Json::Value &IEXdata, std::vector<std::string> &symbolVec)
{
    int i = 0;
    //Step through JSON file until the end is reached
    while(i < IEXdata.size()) {
        symbolVec.push_back(IEXdata[i]["symbol"].asString());
        i++;
    }
}