//
// Created by mjonsson on 4/30/20.
//

#ifndef TRADER_INSTRUMENTV1_H
#define TRADER_INSTRUMENTV1_H

#include <Util.h>
#include <sstream>

class InstrumentV1 {
public:
    long insid;
    string name;
    string urlName;
    int instrument;
    string isin;
    string ticker;
    long sectorId;
    long marketId;
    long branchId;
    long countryId;
    string date;

    string toString()  {
        std::stringstream ss;
        ss << "Insid:" << insid << "\n" << "Name:" << name << "\n" << "UrlName:" << urlName << "\n";
        ss << "Instrument:" << instrument << "\n" << "Isin:" << isin << "\n" << "Ticker:" << ticker << "\n";
        ss << "SectorId:" << sectorId << "\n" << "MarketId:" << marketId << "\n";
        ss << "BranchId:" << branchId << "\n" << "CountryId:" << countryId << "\n";
        ss << "ListingDate:" << date << "\n";
        return ss.str();
    }
};


#endif //TRADER_INSTRUMENTV1_H
