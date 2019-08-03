

#include "main.h"

using namespace Trader;

void fetchLists() {
    vector<string> lists = {"symbols", "regions"};
    for (auto s : lists) {

    }
}


int main(int argc, char** argv) {
//
//    auto v = IEX::ref::updateSymbolList();
//    std::cout << v[8];
    Feeder feed;

    feed.fetchData("MSFT", IEX::INDICATOR::PRICE::CURRENT_PRICE);
    feed.fetchData("MSFT", IEX::INDICATOR::HISTORICAL_PRICES::HIST_PRICE_THREE_MONTH);
    feed.fetchData("MSFT", IEX::INDICATOR::EARNINGS::EARNINGS_ONE_YEAR,
            IEX::INDICATOR::EARNINGS::KEY::ACTUAL_EPS);

    feed.fetchData("MSFT", IEX::INDICATOR::STATS::STATS, IEX::INDICATOR::STATS::KEY::DAY_50_MOV_AVG);
    feed.fetchData("MSFT", IEX::INDICATOR::STATS::STATS, IEX::INDICATOR::STATS::KEY::PE_RATIO);

    ::testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();

////    ActiveAlgorithm active;
////    active.registerWork(MEAN_REVERSION);

    return 0;
//
//        ::testing::InitGoogleMock(&argc, argv);
//        return RUN_ALL_TESTS();

//    InputParser input(argc, argv);
//
//    bool help = input.cmdOptionExists("-h");
//    if (help){
//        std::cout << "Run all unittests: \n" << "./trader -t gtest " << std::endl;
//        std::cout << "Run specific unittests: \n" << "./trader -t gtest -f <val>";
//        std::cout << "\t <val> => request" << std::endl;
//    }
//    const std::string &option = input.getCmdOption("-t");
//
//    if(option.find("gtest") != std::string::npos) {
//        std::cout << "Test mode\n" << std::endl;
//        StartGoogleTest(input, argc ,argv);
//    }

    return 0;
}

