//
// Created by mjonsson on 8/17/19.
//

#ifndef TRADER_JSONWRITER_H
#define TRADER_JSONWRITER_H

#include <mutex>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

namespace IO
{
    using ptree = boost::property_tree::ptree;
    class JsonWriter {
    private:
        JsonWriter() = default;
        ~JsonWriter() = default;
        static JsonWriter *_instance;
        static std::mutex _mx;
    public:

        static JsonWriter& getInstance ();
        void addPropertyTree(std::string && api, const std::string &name, const std::string& type,
                ptree &data, bool clean = true);
    };
}
#endif //TRADER_JSONWRITER_H
