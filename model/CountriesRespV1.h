//
// Created by mjonsson on 4/30/20.
//

#ifndef TRADER_COUNTRIESRESPV1_H
#define TRADER_COUNTRIESRESPV1_H

#include <vector>
#include <boost/property_tree/ptree.hpp>
#include "CountryV1.h"

class CountriesRespV1 {
public:
    boost::property_tree::ptree jsonData;
    std::vector<CountryV1> countries;

    string toString()  {
        std::stringstream ss;
        for(auto &c : countries)
        {
            ss << c.toString() << "\n";
        }
        return ss.str();
    }
};

#endif //TRADER_COUNTRIESRESPV1_H
