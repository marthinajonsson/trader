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
    auto jsonData = branches.jsonData;
    IO::JsonWriter::getInstance().addPropertyTree("BORSDATA", "InstrumentsMeta", "Branchesv1", jsonData);
    save(branches.branches, "Branchesv1.csv");
    branches.branches.clear();
    branches.jsonData.clear();

    auto markets = api.Marketsv1();
    jsonData = markets.jsonData;
    IO::JsonWriter::getInstance().addPropertyTree("BORSDATA", "InstrumentsMeta", "Marketsv1", jsonData);
    save(markets.markets, "Marketsv1.csv");
    markets.markets.clear();
    markets.jsonData.clear();

    auto countries = api.Countriesv1();
    jsonData = countries.jsonData;
    IO::JsonWriter::getInstance().addPropertyTree("BORSDATA", "InstrumentsMeta", "Countriesv1", jsonData);
    save(countries.countries, "Countriesv1.csv");
    countries.countries.clear();
    countries.jsonData.clear();

    auto sectors = api.Sectorsv1();
    jsonData = sectors.jsonData;
    IO::JsonWriter::getInstance().addPropertyTree("BORSDATA", "InstrumentsMeta", "Sectorsv1", jsonData);
    save(sectors.sectors, "Sectorsv1.csv");
    sectors.sectors.clear();
    sectors.jsonData.clear();

    notifyObservers(ALGORITHM::INSTRUMENT_META);
}
