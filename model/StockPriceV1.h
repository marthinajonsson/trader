//
// Created by mjonsson on 5/1/20.
//

#ifndef TRADER_STOCKPRICEV1_H
#define TRADER_STOCKPRICEV1_H

#include <Util.h>
#include <sstream>

class StockPriceV1
{
public:
    string d;
    double h;
    double l;
    double c;
    double o;
    long v;

    string toString()  {
        std::stringstream ss;
        ss << "Date:" << d << "\n" << "HIghest:" << h << "\n" <<
        "Lowest:" << l << "\n" << "Closing:" << c << "\n" <<
        "Opening:" << o << "\n" << "Total volume:" << v << "\n";
        return ss.str();
    }
};

#endif //TRADER_STOCKPRICEV1_H
