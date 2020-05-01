//
// Created by mjonsson on 5/1/20.
//

#ifndef TRADER_KPIV1_H
#define TRADER_KPIV1_H

#include <Util.h>
#include <sstream>

class KpiV1 {
public:
    long i;
    double n;
    string s;

    string toString()  {
        std::stringstream ss;
        ss << "Id:" << i << "\n" << "N:" << n << "\n" << "S:" << s << "\n";
        return ss.str();
    }
};


#endif //TRADER_KPIV1_H
