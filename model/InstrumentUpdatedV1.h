//
// Created by mjonsson on 4/30/20.
//

#ifndef TRADER_INSTRUMENTUPDATEDV1_H
#define TRADER_INSTRUMENTUPDATEDV1_H

#include <Util.h>
#include <sstream>

class InstrumentUpdatedV1 {
public:
    long insid;
    string updateAt;

    string toString()  {
        std::stringstream ss;
        ss << "Insid:" << insid << "\n" << "UpdateAt:" << updateAt << "\n";
        return ss.str();
    }
};

#endif //TRADER_INSTRUMENTUPDATEDV1_H
