//
// Created by mjonsson on 2/16/19.
//

#ifndef TRADER_ALGODISPATCHER_H
#define TRADER_ALGODISPATCHER_H


#include <boost/algorithm/string.hpp>
#include <functional>
#include "MeanReversion.h"
#include "ADX.h"
#include "SMA.h"
#include "Util.h"


class AlgoDispatcher {
private:

public:

    std::function<void()> set(const string& type)
    {
        // TODO send param
        const std::string typeLower = boost::algorithm::to_lower_copy(type);
        if( ALGORITHM::MEAN_REVERSION == typeLower ) {
            //
        }else if ( ALGORITHM::ADX == typeLower ) {
            return std::bind(&ADX::run, &ADX::getInstance());
        }
        else if ( ALGORITHM::SMA == typeLower ) {
            return std::bind(&SMA::run, &SMA::getInstance());
        }
//        return std::bind(&MeanReversion::run, &MeanReversion::getInstance());
    }

};



#endif //TRADER_ALGODISPATCHER_H
