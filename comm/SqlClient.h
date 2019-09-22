//
// Created by mjonsson on 9/22/19.
//

#ifndef TRADER_SQLCLIENT_H
#define TRADER_SQLCLIENT_H

#include <boost/property_tree/json_parser.hpp>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <cppconn/exception.h>

class SqlClient {
private:
    std::string server;
    std::string password;
    std::string username;
    std::string database;
    std::string port;
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
        port = tokenObj.get<std::string>("port", "-1");
        if ("-1" == port) {
            throw std::logic_error("Unexpected error. Could not find token");
        }
        server = tokenObj.get<std::string>("server", "-");
        if ("-" == server) {
            throw std::logic_error("Unexpected error. Could not find token");
        }
        tokenObj.clear();
    }

    int addRow(const std::string& table, const std::string& cols, const std::string& values) {

        try {
            sql::mysql::MySQL_Driver *driver;
            sql::Connection *con;
            sql::Statement *stmt;
            sql::ResultSet  *res;

            int attempts = 0;

            driver = sql::mysql::get_mysql_driver_instance();
            std::string fullserver = "tcp://";
            fullserver = fullserver.append(server).append(":").append(port);
            con = driver->connect("tcp://" + server + ":" + port, username, password);
            while (!con->isValid() && attempts < 6) {
                con->reconnect();
            }

            if (!con->isValid()) {
                delete con;
                return -1;
            }

            con->setSchema("test");
            stmt = con->createStatement();
            stmt->execute("DROP TABLE IF EXISTS test");
            stmt->execute("CREATE TABLE test(id INT, label CHAR(1))");
            res = stmt->executeQuery("SELECT id, label FROM test ORDER BY id ASC");
            while (res->next()) {
                // You can use either numeric offsets...
                std::cout << "id = " << res->getInt(1); // getInt(1) returns the first column
                // ... or column names for accessing results.
                // The latter is recommended.
                std::cout << ", label = '" << res->getString("label") << "'" << std::endl;
            }

            delete res;
            delete stmt;
            delete con;

            return 0;
        }
        catch (sql::SQLException &e) {
            std::cout << "# ERR: SQLException in " << __FILE__;
            std::cout << "(" << __FUNCTION__ << ") on line "
            << __LINE__ << std::endl;
            std::cout << "# ERR: " << e.what();
            std::cout << " (MySQL error code: " << e.getErrorCode();
            std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
        }
    }
};
#endif //TRADER_SQLCLIENT_H
