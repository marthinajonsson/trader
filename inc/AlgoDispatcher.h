//
// Created by mjonsson on 2/16/19.
//

#ifndef TRADER_ALGODISPATCHER_H
#define TRADER_ALGODISPATCHER_H

#include "MeanReversion.h"
#include "Util.h"

#include <string>
#include <functional>


class AlgoDispatcher {
private:

public:

    std::function<void()> set(std::string &type)
    {
        if( MEAN_REVERSION == type ) {
            return std::bind(&MeanReversion::run, &MeanReversion::getInstance());
        }else if ( MOMENTUM == type ) {

        }else if ( SENTIMENT == type ) {

        }else if ( SEASONALITY == type ) {

        }
        return std::bind(&MeanReversion::run, &MeanReversion::getInstance());
    }

};



#endif //TRADER_ALGODISPATCHER_H
