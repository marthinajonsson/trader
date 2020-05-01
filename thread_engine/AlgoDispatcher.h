//
// Created by mjonsson on 2/16/19.
//

#ifndef TRADER_ALGODISPATCHER_H
#define TRADER_ALGODISPATCHER_H


#include <boost/algorithm/string.hpp>
#include <functional>
#include <memory>
#include <StockPrices.h>
#include <Reports.h>
#include <Kpis.h>
#include "Instruments.h"
#include "InstrumentsMeta.h"
#include "StockSplits.h"
#include "ProcessHandler.h"
#include "Algorithm.h"
#include "ADX.h"
#include "SMA.h"

#include "Util.h"

class AlgoDispatcher : Subject {
private:
    ProcessHandler *pHandler;
public:
    AlgoDispatcher()
    {
        pHandler = new ProcessHandler();
        registerObserver(ALGORITHM::ADX, pHandler);
        registerObserver(ALGORITHM::SMA, pHandler);
        registerObserver(ALGORITHM::INSTRUMENT, pHandler);
        registerObserver(ALGORITHM::INSTRUMENT_META, pHandler);
        registerObserver(ALGORITHM::STOCKPRICES, pHandler);
        registerObserver(ALGORITHM::STOCKSPLITS, pHandler);
        registerObserver(ALGORITHM::KPIS, pHandler);
        registerObserver(ALGORITHM::REPORTS, pHandler);
    }

    ~AlgoDispatcher() {
        removeObserver(pHandler);
        delete pHandler;
    }
    std::function<void()> set(const string& type)
    {
        const std::string typeLower = boost::algorithm::to_lower_copy(type);
        if (ALGORITHM::INSTRUMENT_META == typeLower) {
            return std::bind(&InstrumentsMeta::run, &InstrumentsMeta::getInstance());
        }
        else if (ALGORITHM::INSTRUMENT == typeLower) {
            return std::bind(&Instruments::run, &Instruments::getInstance());
        }
        else if (ALGORITHM::STOCKPRICES == typeLower) {
            return std::bind(&StockPrices::run, &StockPrices::getInstance());
        }
        else if (ALGORITHM::STOCKSPLITS == typeLower) {
            return std::bind(&StockSplits::run, &StockSplits::getInstance());
        }
        else if (ALGORITHM::REPORTS == typeLower) {
            return std::bind(&Reports::run, &Reports::getInstance());
        }
        else if (ALGORITHM::KPIS == typeLower) {
            return std::bind(&Kpis::run, &Kpis::getInstance());
        }
        else if ( ALGORITHM::ADX == typeLower ) {
            return std::bind(&ADX::run, &ADX::getInstance());
        }
        else if ( ALGORITHM::SMA == typeLower ) {
            return std::bind(&SMA::run, &SMA::getInstance());
        }
//        return std::bind(&MeanReversion::run, &MeanReversion::getInstance());
    }
};



#endif //TRADER_ALGODISPATCHER_H
