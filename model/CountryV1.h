//
// Created by mjonsson on 4/30/20.
//

#ifndef TRADER_COUNTRYV1_H
#define TRADER_COUNTRYV1_H

#include <Util.h>
#include <sstream>

class CountryV1 {
public:
    long id;
    string name;

    string toString()  {
        std::stringstream ss;
        ss << "Id:" << id << "\n" << "Name:" << name << "\n";
        return ss.str();
    }
};


#endif //TRADER_COUNTRYV1_H
