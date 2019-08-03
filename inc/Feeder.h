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
protected:
    std::ofstream _file;
    string _path;
    static string getPath();
public:
    Feeder() {
        _path = getPath();
    }

    ~Feeder() = default;
    static string getDate();
    void fetchData(string &&symbol, const string& indicator, const string& filterKey = "");
};

#endif //TRADER_FEEDER_H
