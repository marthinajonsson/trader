//
// Created by mjonsson on 2/14/19.
//

#ifndef TRADER_ALGOCONTEXT_H
#define TRADER_ALGOCONTEXT_H

#include "json/json.h"
#include "IEX.h"

#include <functional>
#include <string>
#include <map>

const std::string MEAN_REVERSION = "mean_reversion"; /* what goes up must come down */
const std::string SENTIMENT = "sentiment"; /* buy the rumor, sell the news*/
const std::string MOMENTUM = "momentum"; /* the trend is your friend */
const std::string SEASONALITY = "seasonality"; /* sell in May and go away */
const std::string TECHNICAL_INVEST = "talib"; /* ta-lib */

class AlgoContext {
public:
    AlgoContext(std::string algorithm) : name(algorithm) {

    }
    ~AlgoContext() = default;

    void create() {
        using std::placeholders::_1;

        std::function<Json::Value(const std::string&)> func = std::bind(&IEX::stock::company, _1);
        addToContext("1", func);

        func = std::bind(&IEX::stock::chart, _1);
        addToContext("2", func);

        // read historical data
        // calculate mean or similar
        // compare with previous calculation
        // log and report
    }

    void run() {
        for( auto const& [key, val] : context ) {
            std::cout << key << std::endl;
            std::cout << "********************************" << std::endl;
            std::cout << val("AAPL") << std::endl;
        }
    }

private:
    std::string name;
    std::vector<std::string> list;
    std::map<std::string, std::function<Json::Value(const std::string&)>> context;

    template<typename ftor>
    void addToContext(std::string name, ftor && handler)
    {
        context.insert({
                                   std::move(name),
                                   std::forward<ftor>(handler)
                           });
    }
};




#endif //TRADER_ALGOCONTEXT_H


