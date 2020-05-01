//
// Created by mjonsson on 5/1/20.
//

#include "Kpis.h"
#include <mutex>
#include <KpisApi.h>
#include <JsonWriter.h>

std::mutex m_instr;
static Kpis *instance;

Kpis& Kpis::getInstance()
{
    std::lock_guard<std::mutex> lock(m_instr);
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

    auto result2 = api.Kpisupdatedv1();
    jsonData = result2.jsonData;
    IO::JsonWriter::getInstance().addPropertyTree("BORSDATA", "Kpis", "Kpisupdatedv1", jsonData);

    auto result3 = api.Histkpisv1(1, 1, "X", "X");
    jsonData = result3.jsonData;
    IO::JsonWriter::getInstance().addPropertyTree("BORSDATA", "Kpis", "Histkpisv1", jsonData);

    auto result4 = api.Kpisv1(1, 1, "X", "X");
    jsonData = result4.jsonData;
    IO::JsonWriter::getInstance().addPropertyTree("BORSDATA", "Kpis", "Kpisv1", jsonData);

    notifyObservers(ALGORITHM::KPIS);
}
