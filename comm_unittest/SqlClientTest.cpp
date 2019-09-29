//
// Created by mjonsson on 9/21/19.
//

//
// Created by mjonsson on 9/21/19.
//

#include <gtest/gtest.h>
#include "SqlClient.h"


class SqlClientTest : public ::testing::Test
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

TEST_F(SqlClientTest, CreateDelete) {
    SqlClient sql;
    uint16_t affected_rows = sql.add("companyName", {"date", "ADX"}, {"20xx-xx-xx", "55"});
    ASSERT_TRUE(affected_rows == 1);
    affected_rows = sql.remove("companyName");
    ASSERT_TRUE(affected_rows == 1);
}
