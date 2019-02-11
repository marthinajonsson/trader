//
// Created by mjonsson on 2/7/19.
//

#include <include/gmock/gmock.h>
#include <InputParser.h>


int StartGoogleTest(InputParser &input, int argc, char** argv)
{
    ::testing::InitGoogleMock(&argc, argv);

    const std::string &option = input.getCmdOption("-f");
    if(option.find("request") != std::string::npos) {
        ::testing::GTEST_FLAG(filter) = "RequestTest*";
    }
    return RUN_ALL_TESTS();
}