//
// Created by mjonsson on 5/1/20.
//


#include <gtest/gtest.h>
#include <StockPricesApi.h>

class StockPricesTest : public ::testing::Test
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


TEST_F(StockPricesTest, StockPricesLastV1) {
    StockPricesApi api;
    StockPricesLastRespV1 result = api.Stockpriceslastv1("1");
    vector<StockPriceV1> list = result.stockPricesList;
    for (StockPriceV1 &s : list) {
        BOOST_ASSERT(s.o > 0);
    }
}

TEST_F(StockPricesTest, StockPricesV1) {
    StockPricesApi api;
    StockPricesRespV1 result = api.Stockpricesv1(0, "notUsed", "notUsed");
    vector<StockPriceV1> list = result.stockPricesList;
    for(StockPriceV1 &s : list) {
        BOOST_ASSERT(s.o > 0);
    }
}
