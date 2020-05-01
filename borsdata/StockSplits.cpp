//
// Created by mjonsson on 5/1/20.
//

#include "StockSplits.h"
#include <mutex>
#include <StockSplitsApi.h>
#include <JsonWriter.h>

std::mutex m_instr;
static StockSplits *instance;

StockSplits& StockSplits::getInstance()
{
    std::lock_guard<std::mutex> lock(m_instr);
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
    IO::JsonWriter::getInstance().addPropertyTree("BORSDATA", "StockSplits", "StockSplitsv1", jsonData);

    notifyObservers(ALGORITHM::STOCKSPLITS);
}
