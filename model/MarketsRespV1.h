//
// Created by mjonsson on 4/30/20.
//

#ifndef TRADER_MARKETSRESPV1_H
#define TRADER_MARKETSRESPV1_H

#include <vector>
#include "MarketV1.h"

class MarketsRespV1 {
public:
    std::vector<MarketV1> markets;

    string toString()  {
        std::stringstream ss;
        for(auto &m : markets)
        {
            ss << m.toString() << "\n";
        }
        return ss.str();
    }
    /* string toJson() {

     }*/
};

#endif //TRADER_MARKETSRESPV1_H
