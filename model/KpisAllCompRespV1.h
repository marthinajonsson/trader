//
// Created by mjonsson on 5/1/20.
//

#ifndef TRADER_KPISALLCOMPRESPV1_H
#define TRADER_KPISALLCOMPRESPV1_H

#include "KpiV1.h"

class KpisAllCompRespV1 {
public:
    int kpiId;
    string group;
    string calculation;
    vector<KpiV1> values;

    string toString()  {
        std::stringstream ss;
        ss << "KpiId:" << kpiId << "\n" << "Group:" << group << "\n" << "Calculation:" << calculation << "\n";
        for(auto &v : values)
        {
            ss << v.toString() << "\n";
        }
        return ss.str();
    }
};

#endif //TRADER_KPISALLCOMPRESPV1_H
