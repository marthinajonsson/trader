//
// Created by mjonsson on 8/2/19.
//

#include "Feeder.h"


std::string Feeder::getPath() {
    boost::filesystem::path cwd(boost::filesystem::current_path());
    std::string path = cwd.string() + "/feeds/";
    boost::filesystem::path dir(path);
    if (!(boost::filesystem::exists(path))) {
        if (!boost::filesystem::create_directory(path))
            std::cerr << "Failed to create feed folder" << std::endl;
    }
    return path;
}

void Feeder::fetchByKey(std::string &&symbol, std::string &&key) {
    std::lock_guard<std::mutex> lock(m_write);

    std::string filename = _path + symbol + key;
    _file.open(filename, std::ios::out | std::ios::app);
    std::string value;

    if (0 == key.compare("price")) {
        value = "10.0";
        auto data = IEX::stock::intradayPrices(symbol);
        value = data["close"].asString();
    } else if (0 == key.compare("pe")) {
        auto data = IEX::stock::advancedStats(symbol);
        value = data["pegRatio"].asString();
    }

    _file << value + ",\n";
    _file.close();
}
