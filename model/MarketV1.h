//
// Created by mjonsson on 4/30/20.
//

#ifndef TRADER_MARKETV1_H
#define TRADER_MARKETV1_H

#include <Util.h>
#include <sstream>

class MarketV1 {
public:
    long id;
    string name;
    long countryId;
    string exchangeName;
    bool isIndex;

    string toString()  {
        std::stringstream ss;
        ss << "Id:" << id << "\n" << "Name:" << name << "\n" << "CountryId:" << countryId << "\n";
        ss << "ExchangeName:" << exchangeName << "\n" << "isIndex:" << isIndex << "\n";
        return ss.str();
    }
};


#endif //TRADER_MARKETV1_H
