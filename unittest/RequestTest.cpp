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
    std::cout << jsonData << std::endl;
    ASSERT_TRUE(1==1);
}