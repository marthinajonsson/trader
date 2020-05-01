//
// Created by mjonsson on 5/1/20.
//

#ifndef TRADER_REPORTSRESPV1_H
#define TRADER_REPORTSRESPV1_H

#include <Util.h>
#include "ReportV1.h"

class ReportsRespV1 {
private:
    typedef boost::property_tree::ptree ptree;
public:
    long instrument;
    vector<ReportV1> reports;
    ptree jsonData;

    string toString()  {
        std::stringstream ss;
        ss << "Instrument: " << instrument << "\n";
        for(auto &r : reports)
        {
            ss << r.toString() << "\n";
        }
        return ss.str();
    }
};

#endif //TRADER_REPORTSRESPV1_H
