//
// Created by mjonsson on 4/30/20.
//

#ifndef TRADER_INSTRUMENTUPDATEDRESPV1_H
#define TRADER_INSTRUMENTUPDATEDRESPV1_H

#include <vector>
#include "InstrumentUpdatedV1.h"

class InstrumentUpdatedRespV1 {
public:
    std::vector<InstrumentUpdatedV1> instrumentUpdated;
    boost::property_tree::ptree jsonData;

    string toString()  {
        std::stringstream ss;
        for(auto &i : instrumentUpdated)
        {
            ss << i.toString() << "\n";
        }
        return ss.str();
    }
};

#endif //TRADER_INSTRUMENTUPDATEDRESPV1_H
