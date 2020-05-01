//
// Created by mjonsson on 5/1/20.
//

#ifndef TRADER_STOCKSPLITS_H
#define TRADER_STOCKSPLITS_H


#include "Algorithm.h"

class StockSplits : Algorithm, Subject {
private:
    StockSplits()= default;
    ~StockSplits()= default;
public:
    static StockSplits& getInstance();
    StockSplits(StockSplits const&) = delete;
    void operator=(StockSplits const&) = delete;

    void run() override;
};


#endif //TRADER_STOCKSPLITS_H
