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

    bool exists = IEX::isValidSymbol("aapl");
    ASSERT_TRUE(exists);
}


TEST_F(RequestTest, invalidSymbol) {

    bool exists = IEX::isValidSymbol("aapl2");
    ASSERT_FALSE(exists);
}


TEST_F(RequestTest, company) {

    auto symbols = IEX::ref::getSymbolList();
    std::string symbol = symbols.at(8);
    auto jsonData = IEX::stock::company(symbol);
    std::vector<std::string> argVec;
    IEX::parseArgData(jsonData, argVec, "CEO");


    auto found = std::find(argVec.begin(), argVec.end(), "Hilton H. Howell");
    ASSERT_TRUE(found != argVec.end());
}

TEST_F(RequestTest, chart) {
    auto jsonData = IEX::stock::chart("AAPL");
    std::cout << jsonData << std::endl;
}


TEST_F(RequestTest, news) {
    auto jsonData = IEX::stock::news("AAPL");
    std::cout << jsonData << std::endl;
}


TEST_F(RequestTest, quote) {
    auto jsonData = IEX::stock::quote("AAPL");
    std::cout << jsonData << std::endl;
}


TEST_F(RequestTest, earnings) {
    auto jsonData = IEX::stock::earnings("AAPL");
    std::cout << jsonData << std::endl;
}


TEST_F(RequestTest, dividend) {
    auto jsonData = IEX::ref::dividend("AAPL");
    std::cout << jsonData << std::endl;
}
