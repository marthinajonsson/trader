//
// Created by mjonsson on 5/1/20.
//

#ifndef TRADER_STOCKSPLITRESPV1_H
#define TRADER_STOCKSPLITRESPV1_H

#include "StockSplitV1.h"

class StockSplitRespV1 {
public:
    vector<StockSplitV1> stockSplitList;
    boost::property_tree::ptree jsonData;

    string toString()  {
        std::stringstream ss;
        for(auto &s : stockSplitList)
        {
            ss << s.toString() << "\n";
        }
        return ss.str();
    }
};

#endif //TRADER_STOCKSPLITRESPV1_H
