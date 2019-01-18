#include <iostream>
#include "IEX.h"

int main() {

    Json::Value jsonData = IEX::stock::quote("aapl");

    std::vector<std::string> list;
    IEX::parseData(jsonData, list);

    for (const auto &s : list) {
        std::cout << s << std::endl;
    }

    return 0;
}

