//
// Created by mjonsson on 9/21/19.
//

#include <gtest/gtest.h>
#include <SearchJson.h>

using namespace IO;

class SearchJsonTest : public ::testing::Test
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

TEST_F(SearchJsonTest, findByCompanyName1) {
    std::string url = "../data/UNIBIT_symbols[";
    url.append("OMX").append("].json");

    SearchJson search(url);
    std::vector<std::pair<std::string, std::string>> findings;
    int num = search.exists(findings, "VEONEER", "ticker", {"ticker", "companyName"});
    BOOST_ASSERT(num > 0);
}

TEST_F(SearchJsonTest, findByCompanyName2) {
    std::string url = "../data/UNIBIT_symbols[";
    url.append("NYSE").append("].json");
    SearchJson search(url);
    std::vector<std::pair<std::string, std::string>> findings;
    int num = search.exists(findings, "DIS", "ticker", {"ticker", "companyName"});
    BOOST_ASSERT(num > 0);
}
