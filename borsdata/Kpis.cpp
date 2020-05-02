//
// Created by mjonsson on 5/1/20.
//

#include "Kpis.h"
#include <mutex>
#include <KpisApi.h>
#include <JsonWriter.h>

std::mutex m_kpi;
static Kpis *instance;

Kpis& Kpis::getInstance()
{
    std::lock_guard<std::mutex> lock(m_kpi);
    if(!instance) {
        instance = new Kpis();
    }
    return *instance;
}

void Kpis::run()
{
    KpisApi api;
    auto result = api.Kpislistv1(1, "X", "Y");
    auto jsonData = result.jsonData;
    IO::JsonWriter::getInstance().addPropertyTree("BORSDATA", "Kpis", "Kpislistv1", jsonData);
    save(result.values, "Kpislistv1.csv");
    result.values.clear();
    result.jsonData.clear();

    auto result2 = api.Kpisupdatedv1();
    jsonData = result2.jsonData;
    IO::JsonWriter::getInstance().addPropertyTree("BORSDATA", "Kpis", "Kpisupdatedv1", jsonData);
    save(result.values, "Kpisupdatedv1.csv");
    result.values.clear();
    result.jsonData.clear();

    auto result3 = api.Histkpisv1(1, 1, "X", "X");
    jsonData = result3.jsonData;
    IO::JsonWriter::getInstance().addPropertyTree("BORSDATA", "Kpis", "Histkpisv1", jsonData);
    save(result.values, "Histkpisv1.csv");
    result.values.clear();
    result.jsonData.clear();

    auto result4 = api.Kpisv1(1, 1, "X", "X");
    jsonData = result4.jsonData;
    IO::JsonWriter::getInstance().addPropertyTree("BORSDATA", "Kpis", "Kpisv1", jsonData);
    save(result.values, "Kpisv1.csv");
    result.values.clear();
    result.jsonData.clear();

    notifyObservers(ALGORITHM::KPIS);
}
