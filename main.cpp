#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "main.h"


int main(int argc, char** argv) {

    AlgoContext context("talib");
    context.create();
    context.run();

    AlgoContext context2("momentum");
    context2.create();
    context2.run();


    return 0;



//    StockInfo stock;
//
        ::testing::InitGoogleMock(&argc, argv);
        return RUN_ALL_TESTS();

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

