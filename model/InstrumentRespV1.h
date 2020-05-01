//
// Created by mjonsson on 4/30/20.
//

#ifndef TRADER_INSTRUMENTRESPV1_H
#define TRADER_INSTRUMENTRESPV1_H

#include <vector>
#include "InstrumentV1.h"

class InstrumentRespV1 {
public:
    std::vector<InstrumentV1> instruments;

    string toString()  {
        std::stringstream ss;
        for(auto &i : instruments)
        {
            ss << i.toString() << "\n";
        }
        return ss.str();
    }
};

#endif //TRADER_INSTRUMENTRESPV1_H
