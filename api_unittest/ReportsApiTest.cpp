//
// Created by mjonsson on 5/1/20.
//

#include <gtest/gtest.h>
#include <ReportsApi.h>

class ReportsApiTest : public ::testing::Test
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


TEST_F(ReportsApiTest, ReportsCompoundRespV1) {
    ReportsApi api;
    ReportsCompoundRespV1 result = api.Reportscompoundv1(0, "1");

    vector<ReportV1> reportsR12 = result.reportsR12;
    vector<ReportV1> reportsQuarter = result.reportsQuarter;
    vector<ReportV1> reportsYear = result.reportsYear;

    BOOST_ASSERT(reportsR12.size() > 0);
    for(ReportV1 &r : reportsR12) {
        BOOST_ASSERT(r.stock_Price_Average > 0);
    }
    BOOST_ASSERT(reportsQuarter.size() > 0);
    for(ReportV1 &r : reportsQuarter) {
        BOOST_ASSERT(r.stock_Price_Average > 0);
    }
    BOOST_ASSERT(reportsYear.size() > 0);
    for(ReportV1 &r : reportsYear) {
        BOOST_ASSERT(r.stock_Price_Average > 0);
    }
}


TEST_F(ReportsApiTest, Reportsv1) {
    ReportsApi api;
    ReportsRespV1 result = api.Reportsv1(0, "1");
    vector<ReportV1> reports = result.reports;

    BOOST_ASSERT(reports.size() > 0);
    for(ReportV1 &r : reports) {
        BOOST_ASSERT(r.stock_Price_Average > 0);
    }
}

