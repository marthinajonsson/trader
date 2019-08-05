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
#include "Util.h"


static std::mutex m_write;

class Feeder {
protected:
    std::ofstream _file;
    string _path;
    static string createPath(string &&);
    static string getDate();
public:
    explicit Feeder(string &&test = "") {
        if (test.empty())
            _path = createPath("output_path");
        else
            _path = createPath("test_path");
    }
    ~Feeder() = default;

    const string& getPath() { return _path; }
    void fetchData(string &&symbol, const string& indicator, const string& filterKey = "");
};

#endif //TRADER_FEEDER_H
