#include <iostream>
#include "IEX.h"

int main() {

    Json::Value jsonData = IEX::stock::company("aapl");
    for( Json::Value::const_iterator outer = jsonData.begin() ; outer != jsonData.end() ; outer++ )
    {
        auto keytype = outer.key().type();
        auto val = *outer;
        auto valtype = val.type();
        std::cout << outer.key() << ": " << *outer << std::endl;
    }
    std::vector<std::string> list;
    IEX::parseArgData(jsonData, list, "issueType");

  //  std::cout << list.front() << std::endl;

    return 0;
}

