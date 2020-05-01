//
// Created by mjonsson on 5/1/20.
//

#ifndef TRADER_STOCKPRICESAPI_H
#define TRADER_STOCKPRICESAPI_H

#include "IBorsdata.h"
#include "IStockPricesApi.h"

class StockPricesApi : IStockPricesApi, IBorsdata {
protected:
    static bool replace(string &str, const string &from, const string &to) {
        size_t start_pos = str.find(from);
        if (start_pos == string::npos)
            return false;
        str.replace(start_pos, from.length(), to);
        return true;
    }

public:

    /// <summary>
    /// Returns Last StockPrices for all Instruments. Returns Last StockPrice for all Instrument
    /// </summary>
    /// <param name="version">The requested API version</param>
    /// <returns>StockPricesLastRespV1</returns>
    StockPricesLastRespV1 Stockpriceslastv1(string version) override;

    /// <summary>
    /// Returns StockPrice for Instrument. Max 10 years, if no time filters provided. Returns StockPrice for Instrument
    /// </summary>
    /// <param name="insid">Instrument Id</param>
    /// <param name="from">Date From</param>
    /// <param name="to">Date To</param>
    /// <returns>StockPricesRespV1</returns>
    StockPricesRespV1 Stockpricesv1 (int insid, string from, string to) override;
};

#endif //TRADER_STOCKPRICESAPI_H
