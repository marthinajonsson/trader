//
// Created by mjonsson on 5/1/20.
//

#ifndef TRADER_STOCKSPLITRESPV1_H
#define TRADER_STOCKSPLITRESPV1_H

#include "StockSplitV1.h"

class StockSplitRespV1 {
private:
    typedef boost::property_tree::ptree ptree;
public:
    vector<StockSplitV1> stockSplitList;
    ptree jsonData;

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
