//
// Created by mjonsson on 5/1/20.
//

#ifndef TRADER_ISTOCKSPLITSAPI_H
#define TRADER_ISTOCKSPLITSAPI_H

#include <StockSplitRespV1.h>

class IStockSplitsApi {
public:
    /// <summary>
    /// Returns Stock Splits for all Instruments. Max 1 Year Returns Stock Splits for all Instruments. Max 1 Year
    /// </summary>
    /// <param name="authKey">API Authentication Key</param>
    /// <returns>StockSplitRespV1</returns>
    virtual StockSplitRespV1 StockSplitsv1 (string authKey) = 0;
};

#endif //TRADER_ISTOCKSPLITSAPI_H
