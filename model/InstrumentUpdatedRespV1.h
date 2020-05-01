//
// Created by mjonsson on 4/30/20.
//

#ifndef TRADER_INSTRUMENTUPDATEDRESPV1_H
#define TRADER_INSTRUMENTUPDATEDRESPV1_H

#include <vector>
#include "InstrumentUpdatedV1.h"

class InstrumentUpdatedRespV1 {
private:
    typedef boost::property_tree::ptree ptree;
public:
    std::vector<InstrumentUpdatedV1> instrumentUpdated;
    ptree jsonData;

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
