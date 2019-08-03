//
// Created by mjonsson on 8/2/19.
//

#include "Feeder.h"
#include <algorithm>

string Feeder::getPath() {
    boost::filesystem::path cwd(boost::filesystem::current_path());
    string path = cwd.string() + "/feeds/";
    boost::filesystem::path dir(path);
    if (!(boost::filesystem::exists(path))) {
        if (!boost::filesystem::create_directory(path))
            std::cerr << "Failed to create feed folder" << std::endl;
    }
    return path;
}

void Feeder::fetchData(string &&symbol, const string& indicator, const string& filterKey) {
    std::lock_guard<std::mutex> lock(m_write);

    string pathInd = indicator;
    pathInd.erase(std::remove(pathInd.begin(), pathInd.end(), '/'), pathInd.end());
    string filename = _path + symbol + pathInd;

    _file.open(filename, std::ios::out | std::ios::app);

    Json::Value JValue = IEX::stock::fetch(symbol, indicator, filterKey);
    if (JValue.isArray()) {
        _file << JValue << "\n";
    }
    else if (!JValue.isNull()){
        if (filterKey.empty()) {
            static int aCounter = 0;
            _file << aCounter << ", ";
            _file << JValue.asDouble();
            _file << ",\n";
            aCounter++;
        }
        else {
            static int aCounter2 = 0;
            _file << aCounter2 << ", ";
            _file << JValue;
            _file << ",\n";
            aCounter2++;

        }
    }
    _file.close();
}
