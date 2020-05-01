//
// Created by mjonsson on 5/1/20.
//

#ifndef TRADER_STOCKPRICES_H
#define TRADER_STOCKPRICES_H

#include "Algorithm.h"

class StockPrices : Algorithm, Subject {
private:
    StockPrices()= default;
    ~StockPrices()= default;
public:
    static StockPrices& getInstance();
    StockPrices(StockPrices const&) = delete;
    void operator=(StockPrices const&) = delete;

    void run() override;
};



#endif //TRADER_STOCKPRICES_H
