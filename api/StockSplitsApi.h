//
// Created by mjonsson on 5/1/20.
//

#ifndef TRADER_STOCKSPLITSAPI_H
#define TRADER_STOCKSPLITSAPI_H

#include "IBorsdata.h"
#include "IStockSplitsApi.h"

class StockSplitsApi : IStockSplitsApi, IBorsdata {
public:

    /// <summary>
    /// Returns Stock Splits for all Instruments. Max 1 Year Returns Stock Splits for all Instruments. Max 1 Year
    /// </summary>
    /// <returns>StockSplitRespV1</returns>
    StockSplitRespV1 StockSplitsv1() override;
};

#endif //TRADER_STOCKSPLITSAPI_H
