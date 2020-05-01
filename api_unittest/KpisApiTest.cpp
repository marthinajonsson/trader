//
// Created by mjonsson on 5/1/20.
//

#include <gtest/gtest.h>
#include <KpisApi.h>

class KpisApiTest : public ::testing::Test
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

TEST_F(KpisApiTest, Kpisv1) {
    KpisApi api;
    KpisRespV1 result = api.Kpisv1(1, 1, "X", "Y");
    BOOST_ASSERT(!result.calculation.empty());
}

TEST_F(KpisApiTest, Kpisupdatedv1) {
    KpisApi api;
    KpisCalcUpdatedRespV1 result = api.Kpisupdatedv1();
    BOOST_ASSERT(!result.kpisCalcUpdated.empty());
}

TEST_F(KpisApiTest, Histkpisv1) {
    KpisApi api;
    KpisHistoryRespV1 result = api.Histkpisv1(1, 1, "X", "X");
    BOOST_ASSERT(!result.priceValue.empty());
}

TEST_F(KpisApiTest, Kpislistv1) {
    KpisApi api;
    KpisAllCompRespV1 result = api.Kpislistv1(1, "X", "X");
    BOOST_ASSERT(!result.calculation.empty());
}