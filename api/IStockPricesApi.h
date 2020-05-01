//
// Created by mjonsson on 5/1/20.
//

#ifndef TRADER_ISTOCKPRICESAPI_H
#define TRADER_ISTOCKPRICESAPI_H

#include <Util.h>
#include <StockPricesLastRespV1.h>
#include <StockPricesRespV1.h>

class IStockPricesApi {
protected:
/// <summary>
    /// Returns Last StockPrices for all Instruments. Returns Last StockPrice for all Instrument
    /// </summary>
    /// <param name="version">The requested API version</param>
    /// <returns>StockPricesLastRespV1</returns>
    virtual StockPricesLastRespV1 Stockpriceslastv1 (string version) = 0;
    /// <summary>
    /// Returns StockPrice for Instrument. Max 10 years, if no time filters provided. Returns StockPrice for Instrument
    /// </summary>
    /// <param name="insid">Instrument Id</param>
    /// <param name="from">Date From</param>
    /// <param name="to">Date To</param>
    /// <returns>StockPricesRespV1</returns>
    virtual StockPricesRespV1 Stockpricesv1 (int insid, string from, string to) = 0;
};


#endif //TRADER_ISTOCKPRICESAPI_H
