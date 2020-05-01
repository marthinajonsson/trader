//
// Created by mjonsson on 4/30/20.
//

#ifndef TRADER_SECTORSRESPV1_H
#define TRADER_SECTORSRESPV1_H

#include <vector>
#include "SectorV1.h"

class SectorsRespV1 {
private:
    typedef boost::property_tree::ptree ptree;
public:
    ptree sectorJson;
    std::vector<SectorV1> sectors;

    string toString()  {
        std::stringstream ss;
        for(auto &s : sectors)
        {
            ss << s.toString() << "\n";
        }
        return ss.str();
    }
};


#endif //TRADER_SECTORSRESPV1_H
