//
// Created by mjonsson on 5/1/20.
//


#include <gtest/gtest.h>
#include <StockSplitsApi.h>

class StockSplitsTest : public ::testing::Test
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


TEST_F(StockSplitsTest, StockSplitsv1) {
    StockSplitsApi api;
    StockSplitRespV1 result = api.StockSplitsv1();
    vector<StockSplitV1> list = result.stockSplitList;
    for(StockSplitV1 &s : list) {
        BOOST_ASSERT(!s.comment.empty());
    }
}
