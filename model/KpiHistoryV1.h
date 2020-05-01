//
// Created by mjonsson on 5/1/20.
//

#ifndef TRADER_KPIHISTORYV1_H
#define TRADER_KPIHISTORYV1_H

#include <Util.h>
#include <sstream>

class KpiHistoryV1 {
public:
    int y;
    int p;
    string date;
    double v;

    string toString()  {
        std::stringstream ss;
        ss << "Y:" << y << "\n" << "P:" << p << "\n" << "v:" << v << "\n" << "Date" << date << "\n";
        return ss.str();
    }
};


#endif //TRADER_KPIHISTORYV1_H
