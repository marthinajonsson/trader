//
// Created by mjonsson on 5/1/20.
//

#include <mutex>
#include <InstrumentsMetaApi.h>
#include <JsonWriter.h>
#include "InstrumentsMeta.h"

std::mutex m_instrMeta;
static InstrumentsMeta *instance;

InstrumentsMeta& InstrumentsMeta::getInstance()
{
    std::lock_guard<std::mutex> lock(m_instrMeta);
    if(!instance) {
        instance = new InstrumentsMeta();
    }
    return *instance;
}

void InstrumentsMeta::run()
{
    InstrumentsMetaApi api;
    auto branches = api.Branchesv1();
    auto jsonData = branches.branchesJson;
    IO::JsonWriter::getInstance().addPropertyTree("BORSDATA", "InstrumentsMeta", "Branchesv1", jsonData);

    auto markets = api.Marketsv1();
    jsonData = markets.marketsJson;
    IO::JsonWriter::getInstance().addPropertyTree("BORSDATA", "InstrumentsMeta", "Marketsv1", jsonData);

    auto countries = api.Countriesv1();
    jsonData = countries.countriesJson;
    IO::JsonWriter::getInstance().addPropertyTree("BORSDATA", "InstrumentsMeta", "Countriesv1", jsonData);

    auto sectors = api.Sectorsv1();
    jsonData = sectors.sectorJson;
    IO::JsonWriter::getInstance().addPropertyTree("BORSDATA", "InstrumentsMeta", "Sectorsv1", jsonData);

    notifyObservers(ALGORITHM::INSTRUMENT_META);
}
