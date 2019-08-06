//
// Created by mjonsson on 2/7/19.
//

#include <gtest/gtest.h>
#include "IEX.h"

class RequestTest : public ::testing::Test
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


TEST_F(RequestTest, validSymbol) {

    bool exists = IEX::isValidSymbol("NVDA");
    ASSERT_TRUE(exists);
}


TEST_F(RequestTest, invalidSymbol) {

    bool exists = IEX::isValidSymbol("aapl2");
    ASSERT_FALSE(exists);
}

TEST_F(RequestTest, getSymbolByRegion) {

    IEX::updateReferenceList("ca");
    auto vec = IEX::getSymbolList("ca");
    ASSERT_TRUE(vec.size() > 0);
}

TEST_F(RequestTest, chart) {
    auto jsonData = IEX::fetch("MSFT", IEX::INDICATOR::HISTORICAL_PRICES::HIST_PRICE_SIX_MONTH);
    ASSERT_FALSE(jsonData.empty());
}


TEST_F(RequestTest, earnings) {
    auto jsonData = IEX::fetch("MSFT", IEX::INDICATOR::EARNINGS::EARNINGS_ONE_YEAR);
    ASSERT_FALSE(jsonData.empty());
}


TEST_F(RequestTest, currentPrice) {
    auto jsonData = IEX::fetch("VNE SDB", IEX::INDICATOR::PRICE::CURRENT_PRICE);
    ASSERT_FALSE(jsonData.empty());
}
