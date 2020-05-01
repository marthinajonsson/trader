//
// Created by mjonsson on 5/1/20.
//

#ifndef TRADER_REPORTSCOMPOUNDRESPV1_H
#define TRADER_REPORTSCOMPOUNDRESPV1_H

#include <Util.h>
#include "ReportV1.h"
#include <boost/property_tree/ptree.hpp>

class ReportsCompoundRespV1 {
public:
    long instrument;
    vector<ReportV1> reportsR12;
    vector<ReportV1> reportsQuarter;
    vector<ReportV1> reportsYear;
    boost::property_tree::ptree jsonData;

    string toString()  {
        std::stringstream ss;
        ss << "Instrument: " << instrument << "\n";
        ss << "R12: " << instrument << "\n";
        for(auto &r : reportsR12)
        {
            ss << r.toString() << "\n";
        }
        ss << "Quarter: " << instrument << "\n";
        for(auto &r : reportsQuarter)
        {
            ss << r.toString() << "\n";
        }
        ss << "Year: " << instrument << "\n";
        for(auto &r : reportsYear)
        {
            ss << r.toString() << "\n";
        }
        return ss.str();
    }
};


#endif //TRADER_REPORTSCOMPOUNDRESPV1_H
