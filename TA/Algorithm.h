//
// Created by mjonsson on 8/23/19.
//

#ifndef TRADER_ALGORITHM_H
#define TRADER_ALGORITHM_H

#include "Subject.h"
#include "CSVWriter.h"

class Algorithm {
public:

    template<typename T>
    static void save(std::vector<T> result, std::string fileName) {
        std::string file = "../data/";
        file.append(fileName);
        std::vector<std::string> valuesToPrint;
        for(auto &res : result) {
            valuesToPrint.emplace_back(res.toString());
        }
        save(file, valuesToPrint);
        valuesToPrint.clear();
    }

    static void save(std::string &file, std::vector<std::string> &result) {
        IO::CSVWriter writer(file.c_str());
        writer.addDatainRow(result.begin(), result.end());
    }

    virtual void run() = 0;
};

#endif //TRADER_ALGORITHM_H
