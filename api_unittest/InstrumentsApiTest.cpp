//
// Created by mjonsson on 5/1/20.
//


#include <gtest/gtest.h>
#include "InstrumentsApi.h"

class InstrumentsApiTest : public ::testing::Test
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


TEST_F(InstrumentsApiTest, InstrumentUpgraded) {
    InstrumentsApi api;
    InstrumentUpdatedRespV1 result = api.Instrumentsupdatedv1();
    vector<InstrumentUpdatedV1> list = result.instrumentUpdated;
    for(InstrumentUpdatedV1 &i : list) {
        BOOST_ASSERT(!i.updateAt.empty());
    }
}

TEST_F(InstrumentsApiTest, Instrument) {
    InstrumentsApi api;
    InstrumentRespV1 result = api.Instrumentsv1();
    vector<InstrumentV1> list = result.instruments;
    for(InstrumentV1 &i : list) {
        BOOST_ASSERT(!i.name.empty());
        BOOST_ASSERT(!i.ticker.empty());
        BOOST_ASSERT(!i.date.empty());
    }
}
