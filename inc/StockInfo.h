//
// Created by mjonsson on 1/15/19.
//

#ifndef TRADER_STOCKINFO_H
#define TRADER_STOCKINFO_H

#include <string>
#include <vector>
#include <map>
#include <fstream>

#include "Util.h"
#include "IEX.h"


class StockInfo {
public:
    StockInfo() {
        loadLists();
    };
    ~StockInfo() = default;

    std::string getCompanyName(std::string &symbol) {
        auto companyName = nameMapper[symbol];
        if(!companyName.empty()) {
            return companyName;
        }
        auto jsonData = IEX::stock::company(symbol);
        return jsonData["companyName"].asString();
    }

private:
    std::string symbol;
    std::string fullname;

    std::map<std::string,std::string>  nameMapper;

    void loadLists() {
        Json::Value root;
        int counter = 1;
        root = root["list"];
        auto symbols = IEX::ref::getSymbolList();
        for(const std::string & s : symbols) {
            Json::Value data;
            fullname = IEX::stock::company(s)["companyName"].asString();
            data["companyName"] = fullname;
            data["symbol"] = s;
            root.append(data);
            std::cout << counter << " ";
            counter++;
        }
        writeJSON(root);
    }

    void writeJSON(Json::Value &JSONdata) {
        std::ofstream db_write("../data/symbols.json", std::ios::trunc);
        db_write << JSONdata;
        db_write.close();
    }

};

#endif //TRADER_STOCKINFO_H
