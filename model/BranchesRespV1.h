//
// Created by mjonsson on 4/30/20.
//

#include <vector>
#include <boost/property_tree/ptree.hpp>
#include "BranchV1.h"

class BranchesRespV1 {
public:
    std::vector<BranchV1> branches;
    boost::property_tree::ptree jsonData;

    string toString()  {
        std::stringstream ss;
        for(auto &b : branches)
        {
            ss << b.toString() << "\n";
        }
        return ss.str();
    }
};