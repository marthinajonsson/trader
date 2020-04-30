//
// Created by mjonsson on 4/30/20.
//

#ifndef TRADER_BRANCHV1_H
#define TRADER_BRANCHV1_H

#include <Util.h>
#include <sstream>

class BranchV1 {
public:
    long id;
    string name;
    long sectorId;

    string toString()  {
        std::stringstream ss;
        ss << "Id:" << id << "\n" << "Name:" << name << "\n" << "SectorId:" << sectorId << "\n";
        return ss.str();
    }
};


#endif //TRADER_BRANCHV1_H
