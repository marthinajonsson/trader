//
// Created by mjonsson on 5/1/20.
//


#include <mutex>
#include <StockPricesApi.h>
#include <JsonWriter.h>
#include "StockPrices.h"

std::mutex m_price;
static StockPrices *instance;

StockPrices& StockPrices::getInstance()
{
    std::lock_guard<std::mutex> lock(m_price);
    if(!instance) {
        instance = new StockPrices();
    }
    return *instance;
}

void StockPrices::run()
{
    StockPricesApi api;
    auto result = api.Stockpricesv1(1, "X", "Y");
    auto jsonData = result.jsonData;
    IO::JsonWriter::getInstance().addPropertyTree("BORSDATA", "StockPrices", "Stockpricesv1", jsonData);
    save(result.stockPricesList, "Stockpricesv1.csv");
    result.stockPricesList.clear();
    result.jsonData.clear();

    auto result2 = api.Stockpriceslastv1("1");
    jsonData = result2.jsonData;
    IO::JsonWriter::getInstance().addPropertyTree("BORSDATA", "StockPrices", "Stockpriceslastv1", jsonData);
    save(result.stockPricesList, "Stockpriceslastv1.csv");
    result.stockPricesList.clear();
    result.jsonData.clear();

    notifyObservers(ALGORITHM::STOCKPRICES);
}
