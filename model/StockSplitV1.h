//
// Created by mjonsson on 5/1/20.
//

#ifndef TRADER_STOCKSPLITV1_H
#define TRADER_STOCKSPLITV1_H

#include <Util.h>
#include <sstream>

class StockSplitV1 {
public:
    long instrumentId;
    string splitRate;
    string comment;
    string splitDate;

    string toString()  {
        std::stringstream ss;
        ss << "ID:" << instrumentId << "\n" << "SplitRate:" << splitRate << "\n" <<
           "Comment:" << comment << "\n" << "SplitDate:" << splitDate << "\n";
        return ss.str();
    }
};

#endif //TRADER_STOCKSPLITV1_H
