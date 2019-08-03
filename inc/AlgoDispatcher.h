//
// Created by mjonsson on 2/16/19.
//

#ifndef TRADER_ALGODISPATCHER_H
#define TRADER_ALGODISPATCHER_H

#include "MeanReversion.h"
#include "Util.h"
#include <functional>


class AlgoDispatcher {
private:

public:

    std::function<void()> set(string &type)
    {
        if( ALGORITHM::MEAN_REVERSION == type ) {
            return std::bind(&MeanReversion::run, &MeanReversion::getInstance());
        }else if ( ALGORITHM::MOMENTUM == type ) {

        }else if ( ALGORITHM::SENTIMENT == type ) {

        }else if ( ALGORITHM::SEASONALITY == type ) {

        }
        return std::bind(&MeanReversion::run, &MeanReversion::getInstance());
    }

};



#endif //TRADER_ALGODISPATCHER_H
