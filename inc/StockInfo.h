//
// Created by mjonsson on 1/15/19.
//

#ifndef TRADER_STOCKINFO_H
#define TRADER_STOCKINFO_H

#include <string>
#include <vector>

#include "Util.h"


class StockInfo {
    std::string symbol;
    std::string fullname;
    std::vector<std::string> stockPrices;

    void savePrice(std::string &price) {
        vec_emblace_back(stockPrices, price);
    }


};

#endif //TRADER_STOCKINFO_H
