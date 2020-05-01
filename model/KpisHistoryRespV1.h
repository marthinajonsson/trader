//
// Created by mjonsson on 5/1/20.
//

#ifndef TRADER_KPISHISTORYRESPV1_H
#define TRADER_KPISHISTORYRESPV1_H

#include "KpiHistoryV1.h"

class KpisHistoryRespV1 {
public:
    int kpiId;
    string group;
    string priceValue;
    string reportTime;
    vector<KpiHistoryV1> values;

    string toString()  {
        std::stringstream ss;
        ss << "KpiId:" << kpiId << "\n" << "Group:" << group << "\n" << "ReportTime:" << reportTime << "\n";
        ss << "PriceValue:" << priceValue << "\n";
        for(auto &v : values)
        {
            ss << v.toString() << "\n";
        }
        return ss.str();
    }
};

#endif //TRADER_KPISHISTORYRESPV1_H
