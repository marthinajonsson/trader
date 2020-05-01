//
// Created by mjonsson on 5/1/20.
//

#ifndef TRADER_KPISRESPV1_H
#define TRADER_KPISRESPV1_H

#include "KpiV1.h"

class KpisRespV1 {
public:
    int kpiId;
    string group;
    string calculation;
    KpiV1 value;

    string toString()  {
        std::stringstream ss;
        ss << "KpiId:" << kpiId << "\n" << "Group:" << group << "\n" << "Calculation:" << calculation << "\n" << value.toString() << "\n";
        return ss.str();
    }
};

#endif //TRADER_KPISRESPV1_H
