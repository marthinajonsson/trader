//
// Created by mjonsson on 5/1/20.
//

#ifndef TRADER_APICONFIGURATION_H
#define TRADER_APICONFIGURATION_H

#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <Util.h>
#include <mutex>

class ApiConfiguration {
private:
    ApiConfiguration() = default;
    ~ApiConfiguration() = default;

    static ApiConfiguration *_instance;
    static std::mutex _mx;
public:

    static ApiConfiguration &getInstance() {
        std::lock_guard<std::mutex> lock(_mx);
        if (!_instance) {
            _instance = new ApiConfiguration();
        }
        return *_instance;
    }

    ApiConfiguration(const ApiConfiguration &) = delete;

    ApiConfiguration(ApiConfiguration &&) = delete;

    ApiConfiguration &operator=(const ApiConfiguration &) = delete;

    ApiConfiguration &operator=(ApiConfiguration &&) = delete;

    static string getBase () {
        boost::property_tree::ptree JSONconfig;
        string val;
        boost::property_tree::read_json("../data/config.json", JSONconfig);
        auto valObj = JSONconfig.get_child("BORSDATA");
        val = valObj.get<string>("base", "-");
        if ("-" == val) {
            throw std::logic_error("Unexpected error. Could not find base");
        }
        return val;
    }

    static string getToken () {
        boost::property_tree::ptree JSONconfig;
        string val;
        boost::property_tree::read_json("../data/config.json", JSONconfig);
        auto valObj = JSONconfig.get_child("BORSDATA");
        val = valObj.get<string>("token", "-");
        if ("-" == val) {
            throw std::logic_error("Unexpected error. Could not find token");
        }
        return val;
    }

    static string getOutputPath () {
        boost::property_tree::ptree JSONconfig;
        string val;
        boost::property_tree::read_json("../data/config.json", JSONconfig);
        auto valObj = JSONconfig.get_child("BORSDATA");
        val = valObj.get<string>("output_path", "-");
        if ("-" == val) {
            throw std::logic_error("Unexpected error. Could not find output_path");
        }
        return val;
    }

    static string getDebugPath () {
        boost::property_tree::ptree JSONconfig;
        string val;
        boost::property_tree::read_json("../data/config.json", JSONconfig);
        auto valObj = JSONconfig.get_child("BORSDATA");
        val = valObj.get<string>("test_path", "-");
        if ("-" == val) {
            throw std::logic_error("Unexpected error. Could not find test_path");
        }
        return val;
    }
};

#endif //TRADER_APICONFIGURATION_H
