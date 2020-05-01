//
// Created by mjonsson on 5/1/20.
//
#include <gtest/gtest.h>
#include "InstrumentsMetaApi.h"

class InstrumentsMetaApiTest : public ::testing::Test
{
protected:


    void SetUp() override
    {
        //
    }

    void TearDown() override
    {
        //
    }
};


TEST_F(InstrumentsMetaApiTest, BranchV1) {
    InstrumentsMetaApi api;
    BranchesRespV1 result = api.Branchesv1();
    vector<BranchV1> list = result.branches;
    for(BranchV1 &b : list) {
        BOOST_ASSERT(!b.name.empty());
    }
}

TEST_F(InstrumentsMetaApiTest, MarketV1) {
    InstrumentsMetaApi api;
    MarketsRespV1 result = api.Marketsv1();
    vector<MarketV1> list = result.markets;
    for(MarketV1 &m : list) {
        BOOST_ASSERT(!m.name.empty());
    }
}

TEST_F(InstrumentsMetaApiTest, SectorV1) {
    InstrumentsMetaApi api;
    SectorsRespV1 result = api.Sectorsv1();
    vector<SectorV1> list = result.sectors;
    for(SectorV1 &s : list) {
        BOOST_ASSERT(!s.name.empty());
    }
}

TEST_F(InstrumentsMetaApiTest, CountryV1) {
    InstrumentsMetaApi api;
    CountriesRespV1 result = api.Countriesv1();
    vector<CountryV1> list = result.countries;
    for(CountryV1 &c : list) {
        BOOST_ASSERT(!c.name.empty());
    }
}
