//
// Created by mjonsson on 5/1/20.
//

#ifndef TRADER_STOCKPRICESLASTRESPV1_H
#define TRADER_STOCKPRICESLASTRESPV1_H

#include "StockPriceV1.h"

class StockPricesLastRespV1 {
private:
    typedef boost::property_tree::ptree ptree;
public:
    long instrument;
    vector<StockPriceV1> stockPricesList;
    ptree jsonData;

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


#endif //TRADER_STOCKPRICESLASTRESPV1_H
