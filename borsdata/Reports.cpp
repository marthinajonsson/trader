//
// Created by mjonsson on 5/1/20.
//

#include "Reports.h"
#include <mutex>
#include <JsonWriter.h>
#include <ReportsApi.h>

std::mutex m_report;
static Reports *instance;

Reports& Reports::getInstance()
{
    std::lock_guard<std::mutex> lock(m_report);
    if(!instance) {
        instance = new Reports();
    }
    return *instance;
}

void Reports::run()
{
    ReportsApi api;
    auto result = api.Reportsv1(1, "json");
    auto jsonData = result.jsonData;
    IO::JsonWriter::getInstance().addPropertyTree("BORSDATA", "Reports", "Reportsv1", jsonData);

    auto result2 = api.Reportscompoundv1(1, "1");
    jsonData = result2.jsonData;
    IO::JsonWriter::getInstance().addPropertyTree("BORSDATA", "Reports", "Reportscompoundv1", jsonData);

    notifyObservers(ALGORITHM::REPORTS);
}
