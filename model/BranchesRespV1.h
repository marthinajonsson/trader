//
// Created by mjonsson on 4/30/20.
//

#include <vector>
#include <boost/property_tree/ptree.hpp>
#include "BranchV1.h"

class BranchesRespV1 {
private:
    typedef boost::property_tree::ptree ptree;
public:
    std::vector<BranchV1> branches;
    ptree branchesJson;

    string toString()  {
        std::stringstream ss;
        for(auto &b : branches)
        {
            ss << b.toString() << "\n";
        }
        return ss.str();
    }
};