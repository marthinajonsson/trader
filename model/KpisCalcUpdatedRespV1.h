//
// Created by mjonsson on 5/1/20.
//

#ifndef TRADER_KPISCALCUPDATEDRESPV1_H
#define TRADER_KPISCALCUPDATEDRESPV1_H

#include <Util.h>
#include <sstream>

class KpisCalcUpdatedRespV1 {
private:
    typedef boost::property_tree::ptree ptree;
public:
    string kpisCalcUpdated;
    ptree jsonData;

    string toString()  {
        std::stringstream ss;
        ss << "KpisCalcUpdated:" << kpisCalcUpdated << "\n";
        return ss.str();
    }
};

#endif //TRADER_KPISCALCUPDATEDRESPV1_H
