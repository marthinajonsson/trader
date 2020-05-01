//
// Created by mjonsson on 5/1/20.
//


#include <mutex>
#include <InstrumentsApi.h>
#include <JsonWriter.h>
#include "Instruments.h"

std::mutex m_instr;
static Instruments *instance;

Instruments& Instruments::getInstance()
{
    std::lock_guard<std::mutex> lock(m_instr);
    if(!instance) {
        instance = new Instruments();
    }
    return *instance;
}

void Instruments::run()
{
    InstrumentsApi api;
    auto result = api.Instrumentsv1();
    auto jsonData = result.jsonData;
    IO::JsonWriter::getInstance().addPropertyTree("BORSDATA", "Instruments", "Instrumentsv1", jsonData);

    auto result2 = api.Instrumentsupdatedv1();
    jsonData = result2.jsonData;
    IO::JsonWriter::getInstance().addPropertyTree("BORSDATA", "Instruments", "Instrumentsupdatedv1", jsonData);

    notifyObservers(ALGORITHM::INSTRUMENT);
}
