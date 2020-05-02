//
// Created by mjonsson on 5/1/20.
//

#include "StockSplits.h"
#include <mutex>
#include <StockSplitsApi.h>
#include <JsonWriter.h>

std::mutex m_split;
static StockSplits *instance;

StockSplits& StockSplits::getInstance()
{
    std::lock_guard<std::mutex> lock(m_split);
    if(!instance) {
        instance = new StockSplits();
    }
    return *instance;
}

void StockSplits::run()
{
    StockSplitsApi api;
    auto result = api.StockSplitsv1();
    auto jsonData = result.jsonData;
    IO::JsonWriter::getInstance().addPropertyTree("BORSDATA", "StockSplitAnalyzer", "StockSplitsv1", jsonData);
    save(result.stockSplitList, "StockSplitsv1.csv");
    result.stockSplitList.clear();
    result.jsonData.clear();

    notifyObservers(ALGORITHM::STOCKSPLITS);
}
