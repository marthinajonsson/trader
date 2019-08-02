//
// Created by mjonsson on 1/11/19.
//

#include "IEX.h"
#include "main.h"



namespace {

    std::size_t callback(const char *in, std::size_t size, std::size_t num, std::string *out) {
        const std::size_t totalBytes(size * num);
        out->append(in, totalBytes);
        return totalBytes;
    }
}

void IEX::parseData(const Json::Value &IEXdata, std::vector<std::string> &argVec) {

    for (Json::Value::const_iterator it=IEXdata.begin(); it!=IEXdata.end(); ++it) {
        std::string data = it.key().asString() + ':' + it->asString();

        argVec.emplace_back(data);
    }
}

void IEX::parseArgData(const Json::Value &IEXdata, std::vector<std::string> &argVec, std::string &&arg)
{
   if (!IEXdata.isMember(arg)) {
        std::cout << "Key doesn't exists" << std::endl;
        return;
    }

    auto val = IEXdata[arg];
    if (val.isArray()) {
        for (const auto &v : val) {
            argVec.emplace_back(v.asString());
        }
    }
    else {
        std::string result = val.asString();
        argVec.emplace_back(result);

    }
}

bool IEX::isValidSymbol(const std::string &symbol)
{
    std::vector<std::string> symbolList = IEX::ref::getSymbolList();
    std::string symbolCopy = symbol;
    boost::to_upper(symbolCopy);
    return std::find(symbolList.begin(), symbolList.end(), symbolCopy) != symbolList.end();
}


void IEX::sendHttpGetRequest(Json::Value &jsonData, std::string &url)
{
    Json::Value JSONconfig;
    std::string token;
    std::ifstream config("../data/config.json", std::ifstream::binary);
    if (!config.is_open()) {
        std::cerr << "token is missing, could not find config.json" << std::endl;
        return;
    }
    else {
        config >> JSONconfig;
        config.close();
        token = JSONconfig["token"].asString();
    }

    url += "/" + token;
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

    Json::CharReaderBuilder builder;
    Json::CharReader * reader = builder.newCharReader();
    std::string errors;

    bool result = reader->parse(httpData.get()->c_str(), httpData->end().base(), &jsonData, &errors);

    if(!result) {
        std::cout << "False curl request: " << url << std::endl;
    }
    delete reader;

}
