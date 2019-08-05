//
// Created by mjonsson on 8/2/19.
//

#include "Feeder.h"
#include "IEX.h"
#include <algorithm>
#include <regex>

namespace fs = boost::filesystem;

string Feeder::getDate() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    auto year = 1900 + ltm->tm_year;
    auto month = 1 + ltm->tm_mon;
    auto day = ltm->tm_mday;
    string y = std::to_string(year);
    string m = std::to_string(month);
    string d = std::to_string(day);
    y = y.append("-");
    y = y.append(m);
    y = y.append("-");
    y = y.append(d);
    return y;
}

string Feeder::createPath(string &&key)
{
    Json::Value root;
    vector<string> list;
    string url = "../data/config.json";
    std::ifstream db_read(url, std::ifstream::binary);
    db_read >> root;
    db_read.close();
    string path = root[key].asString();
    fs::path dir(path);
    if (!fs::exists(path)) {
        if (!fs::create_directory(path))
            std::cerr << "Failed to create feed folder" << std::endl;
    }
    return path;
}

void Feeder::fetchData(string &&symbol, const string& indicator, const string& filterKey) {
    std::lock_guard<std::mutex> lock(m_write);

    string pathInd = indicator;
    if (string::npos != pathInd.find('/'))
        pathInd = std::regex_replace(pathInd, std::regex("/"), "_");

    string filename = _path;
    filename.append(symbol).append("_").append(pathInd);
    if (!filterKey.empty()) {
        string pathKey = filterKey;
        if (string::npos != pathKey.find('/'))
            pathKey = std::regex_replace(pathKey, std::regex("/"), "_");
        filename.append("_");
        filename.append(pathKey);
    }
    _file.open(filename, std::ios::out | std::ios::app);

    Json::Value JValue = IEX::stock::fetch(symbol, indicator, filterKey);
    if (JValue.isArray()) {
        _file << JValue << "\n";
    }
    else if (!JValue.isNull()){
        if (filterKey.empty()) {
            string date = getDate();
            _file << date << ", ";
            _file << JValue.asDouble();
            _file << ",\n";
        }
        else {
            static int aCounter2 = 0;
            string date = getDate();
            _file << date << ", ";
            _file << JValue;
            _file << ",\n";

        }
    }
    _file.close();
}
