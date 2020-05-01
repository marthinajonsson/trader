//
// Created by mjonsson on 5/1/20.
//

#ifndef TRADER_STOCKPRICESRESPV1_H
#define TRADER_STOCKPRICESRESPV1_H

#include "StockPriceV1.h"

class StockPricesRespV1 {
public:
    long instrument;
    vector<StockPriceV1> stockPricesList;

    string toString()  {
        std::stringstream ss;
        ss << "Instrument:" << instrument << "\n";
        for(auto &s : stockPricesList)
        {
            ss << s.toString() << "\n";
        }
        return ss.str();
    }
};

#endif //TRADER_STOCKPRICESRESPV1_H
