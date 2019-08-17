//
// Created by mjonsson on 8/17/19.
//

#include "JsonWriter.h"

using namespace IO;
JsonWriter* JsonWriter::_instance = nullptr;
std::mutex JsonWriter::_mx;

JsonWriter& JsonWriter::getInstance ()
{
    std::lock_guard<std::mutex> lock(_mx);
    if(!_instance) {
        _instance = new JsonWriter();
    }
    return *_instance;
}

void JsonWriter::addPropertyTree(std::string && api, const std::string &name, const std::string& type,
                     ptree &data, bool clean)
{
    ptree root;
    std::string url = "../data/" + api + "_" + name + ".json";
    if(!clean) {
        try{
            boost::property_tree::read_json(url, root);
        }catch(std::exception &){

        }
    }
    root.add_child(type, data);
    boost::property_tree::write_json(url, root);
}