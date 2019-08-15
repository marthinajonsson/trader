//
// Created by mjonsson on 8/15/19.
//

#ifndef TRADER_SEARCHJSON_H
#define TRADER_SEARCHJSON_H

#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <optional>
#include <algorithm>
#include <iostream>
#include <string>
#include <mutex>

using ptree = boost::property_tree::ptree;

class SearchJson {
private:
    std::string _filename;
    std::mutex _m;
    ptree _root;
public:
    explicit SearchJson (const std::string& filename) : _filename(filename) {
        std::lock_guard<std::mutex> lock(_m);
        boost::property_tree::read_json(filename, _root);
    }
    ~SearchJson() = default;

    bool exists(std::vector<std::pair<std::string, std::string>>& findings, const std::string &pattern,
            const std::string & head, const std::vector<std::string> &keys)
    {
        auto tickerIt = _root.get_child_optional( head );
        if (!tickerIt) {
            return false;
        }
        bool found = false;
        std::vector<ptree> treeResult;
        BOOST_FOREACH(const boost::property_tree::ptree::value_type &c, _root.get_child("ticker"))
        {
            for (const std::string& key : keys) {
                auto val = c.second.get<std::string> (key);

                if (found) {
                    findings.emplace_back(std::make_pair(key, val));
                }

                if (std::string::npos != val.find(pattern)) {
                    treeResult.emplace_back(c.second);
                    findings.emplace_back(std::make_pair(key, val));
                    found = true;
                }
            }

            if (found) {
                for (const ptree& pt : treeResult) {
                    boost::property_tree::write_json(std::cout, pt);
                }
                return true;
            }
        }
        return false;
    }
};

#endif //TRADER_SEARCHJSON_H
