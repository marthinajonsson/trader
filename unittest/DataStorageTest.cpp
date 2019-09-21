//
// Created by mjonsson on 9/21/19.
//

#include <gtest/gtest.h>
#include <DataStorage.h>


class DataStorageTest : public ::testing::Test
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

TEST_F(DataStorageTest, addRow) {
    DataStorage db;
    db.addRow("VEONEER", "ADX", "76");
}

TEST_F(DataStorageTest, selectTable) {
    DataStorage db;
    db.addRow("VEONEER", "SMA", "24");
    db.selectTable("VEONEER");
}