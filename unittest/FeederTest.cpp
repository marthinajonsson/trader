//
// Created by mjonsson on 8/5/19.
//


#include <gtest/gtest.h>
#include "Feeder.h"
#include "IEX.h"

class FeederTest : public ::testing::Test
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

namespace fs = boost::filesystem;

TEST_F(FeederTest, simple) {
    Feeder feed("test");
    string path = feed.getPath();
    fs::path fs_path(path);
    if (fs::exists(fs_path)) {
        for (fs::directory_iterator endIt, it(fs_path); it != endIt; it++) {
            fs::remove_all(it->path());
        }
    }
    ASSERT_TRUE(fs::is_empty(fs_path));

    feed.fetchData("NVDA", IEX::INDICATOR::PRICE::CURRENT_PRICE);
    feed.fetchData("MSFT", IEX::INDICATOR::PRICE::CURRENT_PRICE);

    ASSERT_FALSE(fs::is_empty(fs_path));
    for (fs::directory_iterator endIt, it(fs_path); it != endIt; it++) {
        size_t size = fs::file_size(it->path());
        ASSERT_TRUE(size > 0);
    }
}

TEST_F(FeederTest, medium) {
    Feeder feed("test");
    string path = feed.getPath();
    fs::path fs_path(path);
    if (fs::exists(fs_path)) {
        for (fs::directory_iterator endIt, it(fs_path); it != endIt; it++) {
            fs::remove_all(it->path());
        }
    }
    ASSERT_TRUE(fs::is_empty(fs_path));

    feed.fetchData("MSFT", IEX::INDICATOR::EARNINGS::EARNINGS_ONE_YEAR,
                   IEX::INDICATOR::EARNINGS::KEY::ACTUAL_EPS);
    feed.fetchData("MSFT", IEX::INDICATOR::STATS::STATS, IEX::INDICATOR::STATS::KEY::DAY_50_MOV_AVG);
    feed.fetchData("MSFT", IEX::INDICATOR::STATS::STATS, IEX::INDICATOR::STATS::KEY::PE_RATIO);

    feed.fetchData("NVDA", IEX::INDICATOR::EARNINGS::EARNINGS_ONE_YEAR,
                   IEX::INDICATOR::EARNINGS::KEY::ACTUAL_EPS);
    feed.fetchData("NVDA", IEX::INDICATOR::STATS::STATS, IEX::INDICATOR::STATS::KEY::DAY_50_MOV_AVG);
    feed.fetchData("NVDA", IEX::INDICATOR::STATS::STATS, IEX::INDICATOR::STATS::KEY::PE_RATIO);

    ASSERT_FALSE(fs::is_empty(fs_path));
    for (fs::directory_iterator endIt, it(fs_path); it != endIt; it++) {
        size_t size = fs::file_size(it->path());
        ASSERT_TRUE(size > 0);
    }
}

TEST_F(FeederTest, complex) {
    Feeder feed("test");
    string path = feed.getPath();
    fs::path fs_path(path);
    if (fs::exists(fs_path)) {
        for (fs::directory_iterator endIt, it(fs_path); it != endIt; it++) {
            fs::remove_all(it->path());
        }
    }
    ASSERT_TRUE(fs::is_empty(fs_path));

    feed.fetchData("MSFT", IEX::INDICATOR::HISTORICAL_PRICES::HIST_PRICE_THREE_MONTH);
    feed.fetchData("NVDA", IEX::INDICATOR::HISTORICAL_PRICES::HIST_PRICE_THREE_MONTH);

    ASSERT_FALSE(fs::is_empty(fs_path));
    for (fs::directory_iterator endIt, it(fs_path); it != endIt; it++) {
        size_t size = fs::file_size(it->path());
        ASSERT_TRUE(size > 0);
    }
}
