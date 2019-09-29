//
// Created by mjonsson on 9/22/19.
//

#ifndef TRADER_SQLCLIENT_H
#define TRADER_SQLCLIENT_H

#ifndef STATIC_CONCPP
#define STATIC_CONCPP
#endif

#include <boost/property_tree/json_parser.hpp>

#include <mysqlx/xdevapi.h> // mysql connector 8.0

class SqlClient {
private:
    std::string server;
    std::string password;
    std::string username;
    std::string database;
    int port;

    mysqlx::Schema connectDb() {
        mysqlx::SessionSettings settings(server, port, username, password, database);
        mysqlx::Session sess(settings);
        return sess.getSchema("test");
    }

    void closeDb(mysqlx::Session &session) {
        session.close();
    }

public:
    ~SqlClient() = default;
    SqlClient()
    {
        boost::property_tree::ptree JSONconfig;
        boost::property_tree::read_json("../data/config.json", JSONconfig);
        auto tokenObj = JSONconfig.get_child("LOCAL_SERVER");
        username = tokenObj.get<std::string>("username", "-");
        if ("-" == username) {
            throw std::logic_error("Unexpected error. Could not find token");
        }
        password = tokenObj.get<std::string>("password", "-");
        if ("-" == password) {
            throw std::logic_error("Unexpected error. Could not find token");
        }
        database = tokenObj.get<std::string>("domain", "-");
        if ("-" == database) {
            throw std::logic_error("Unexpected error. Could not find token");
        }
        port = tokenObj.get<int>("port", -1);
        if (-1 == port) {
            throw std::logic_error("Unexpected error. Could not find token");
        }
        server = tokenObj.get<std::string>("server", "-");
        if ("-" == server) {
            throw std::logic_error("Unexpected error. Could not find token");
        }
        tokenObj.clear();
    }

    uint16_t add(const std::string &tableName, const std::vector<std::string> &col, const std::vector<std::string> &value) {
        mysqlx::Schema db = connectDb();
        mysqlx::Table table(db, tableName);
        mysqlx::Row row;
        auto result = table.insert(col.at(0), col.at(1))
                .values(1, value.at(0))
                .values(2, value.at(1))
                .execute();

        uint16_t affected = result.getAffectedItemsCount();

        closeDb(db.getSession());
        return affected;
    }

    void read(std::string &tableName, std::string col = "") {
        mysqlx::Schema db = connectDb();
        mysqlx::Table table = db.getTable(tableName);
        table.select();

        std::string filter = col == "" ? "*" : filter;
        mysqlx::RowResult res = table.select("date", filter)
                .where("name like :param")
                .orderBy("name")
                .bind("param", "m%").execute();

        mysqlx::Row row;

        while ((row = res.fetchOne()))
        {
            std::cout << "Name: " << row[0] << std::endl;
            std::cout << " Age: " << row[1] << std::endl;
            int age = row[1];
            // One needs explicit .get<int>() as otherwise operator<() is ambiguous
            bool youth = row[age].get<int>() < 18;
            // Alternative formulation
            bool youth2 = (int)row[age] < 18;
        }
        closeDb(db.getSession());
    }

    uint16_t update(const std::string &tableName, std::string col = "") {
        mysqlx::Schema db = connectDb();
        mysqlx::Table table = db.getTable(tableName);
        auto res = table.update()
            .set(col, "value")
            .where("colName like :param")
            .bind("param", "m%").execute();

        uint16_t affected = res.getAffectedItemsCount();
        closeDb(db.getSession());
        return affected;
    }

    uint16_t remove(const std::string &tableName) {
        mysqlx::Schema db = connectDb();
        mysqlx::Table table = db.getTable(tableName);
        auto res = table.remove().execute();
        uint16_t affected = res.getAffectedItemsCount();
        closeDb(db.getSession());
        return affected;
    }
};
#endif //TRADER_SQLCLIENT_H
