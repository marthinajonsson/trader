//
// Created by mjonsson on 9/1/19.
//

#ifndef TRADER_DATASTORAGE_H
#define TRADER_DATASTORAGE_H

#include <mysql++/mysql++.h>
#include <string>
#include <boost/property_tree/json_parser.hpp>

class DataStorage {
private:
    std::string server;
    std::string password;
    std::string username;
    std::string database;
    int port;
public:
    ~DataStorage() = default;
    DataStorage()
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

    mysqlpp::Query createTable(mysqlpp::Connection &conn, const std::string &table) {
        std::string queryStr = "CREATE TABLE IF NOT EXISTS " + table;
        queryStr.append(" (\n");
        queryStr.append("rowId INT AUTO_INCREMENT,\n");
        queryStr.append("stockId INT DEFAULT 0,\n");
        queryStr.append("date DATE,\n");
        queryStr.append("price INT DEFAULT 0,\n");
        queryStr.append("SMA VARCHAR(255),\n");
        queryStr.append("ADX VARCHAR(255),\n");
        queryStr.append("PE VARCHAR(255),\n");
        queryStr.append("PRIMARY KEY(stockId)\n");
        queryStr.append(") ENGINE=INNODB;");
        mysqlpp::Query response = conn.query(queryStr);

        const char* err = response.error();
        int errNo = response.errnum();
        std::cout << err << " " << errNo << std::endl;
        return  response;
    }

    template<typename T>
    int addRow(const std::string& table, const std::string& cols, const std::string& values) {

        try {
            mysqlpp::Connection conn;
            auto connected = conn.connect(database.c_str(), server.c_str(),
                                          username.c_str(), password.c_str(), 3307);

            if (!connected && !conn.ping()) {
                std::cerr << "Can't connect to server" << std::endl;
                return -1;
            }

            mysqlpp::Query result = createTable(conn, table);

            std::string queryStr = "INSERT INTO " + table;
            queryStr.append("(").append(cols).append(")\n");
            queryStr.append("VALUES(").append(values).append(")");
            mysqlpp::Query response = conn.query(queryStr);
            if ("1 row(s) affected" != response.str())
                std::cerr << response.str();

            conn.disconnect();
            return 0;
        }
        catch (std::exception &ex) {
            std::cerr << ex.what() << std::endl;
            return -1;
        }
    }

    int deleteRows(const std::string &table) {

        try {
            mysqlpp::Connection conn;
            auto connected = conn.connect(database.c_str(), server.c_str(),
                                          username.c_str(), password.c_str(), 3307);

            if (!connected && !conn.ping()) {
                std::cerr << "Can't connect to server" << std::endl;
                return -1;
            }


            std::string queryStr = "DELETE FROM " + table;
            queryStr.append(";");
            mysqlpp::Query response = conn.query(queryStr);

            const char *err = response.error();
            int errNo = response.errnum();
            std::cout << err << " " << errNo << std::endl;
            return 0;
        }
        catch (std::exception &ex)
        {
            std::cerr << ex.what() << std::endl;
            return -1;
        }
    }

    int deleteTable(const std::string &table) {

        try {
            mysqlpp::Connection conn;
            auto connected = conn.connect(database.c_str(), server.c_str(),
                                          username.c_str(), password.c_str(), 3307);

            if (!connected && !conn.ping()) {
                std::cerr << "Can't connect to server" << std::endl;
                return -1;
            }


            std::string queryStr = "DROP TABLE " + table;
            queryStr.append(";");
            mysqlpp::Query response = conn.query(queryStr);

            const char *err = response.error();
            int errNo = response.errnum();
            std::cout << err << " " << errNo << std::endl;
            return 0;
        }
        catch (std::exception &ex)
        {
            std::cerr << ex.what() << std::endl;
            return -1;
        }
    }
};

#endif //TRADER_DATASTORAGE_H
