//
// Created by mjonsson on 8/2/19.
//

#ifndef TRADER_FEEDER_H
#define TRADER_FEEDER_H

#include <boost/algorithm/string.hpp>
#include <boost/filesystem.hpp>
#include <fstream>
#include <iostream>
#include <mutex>
#include "IEX.h"

static std::mutex m_write;

class Feeder {
private:
    std::ofstream _file;
    std::string _path;
    std::string getPath();
public:
    Feeder() {
        _path = getPath();
        IEX::ref::getSymbolList();
    }

    ~Feeder() = default;

    void fetchByKey(std::string &&symbol, std::string &&key);
};

#endif //TRADER_FEEDER_H
