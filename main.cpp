
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <Feeder.h>
#include "main.h"

using namespace Trader;

int main(int argc, char** argv) {

    auto v = IEX::ref::updateSymbolList();
    std::cout << v[8];
//    Feeder feed;
//
//    feed.fetchByKey("NVDA", "price");
//    feed.fetchByKey("NVDA", "pe");
//    feed.fetchByKey("MSFT", "price");
//    feed.fetchByKey("MSFT", "pe");
//    feed.fetchByKey("NVDA", "price");
//    feed.fetchByKey("NVDA", "pe");
//    feed.fetchByKey("MSFT", "price");
//    feed.fetchByKey("MSFT", "pe");
//    return RUN_ALL_TESTS();

//    TA_RetCode ret = TA_Initialize();
//
//    if(ret != TA_RetCode::TA_SUCCESS) {
//        std::cerr << "Cannot initialize TA-Lib (%d)!\n" << ret << std::endl;
//        return -1;
//    }
////    ActiveAlgorithm active;
////    active.registerWork(MEAN_REVERSION);
//
//    TA_Shutdown();
//
//
//    Json::Value jsonData = IEX::stock::quote("AAPL");

    return 0;
//
//
//
//    StockInfo stock;
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

