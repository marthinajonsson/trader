//
// Created by mjonsson on 2/14/19.
//

#ifndef TRADER_ALGOCONTEXT_H
#define TRADER_ALGOCONTEXT_H

#include <functional>
#include <string>
#include <IEX.h>
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

    void createPipeline() {
        using std::placeholders::_1;

        std::function<Json::Value(const std::string&)> func = std::bind(&IEX::stock::company, _1);
        installPipeline("1", func);

        func = std::bind(&IEX::stock::earnings, _1);
        installPipeline("2", func);


        // read historical data
        // calculate mean or similar
        // compare with previous calculation
        // log and report
    }

    std::map<std::string, std::function<Json::Value(const std::string&)>> getPipeline() {
        return pipeline;
    }


private:
    std::string name;
    std::vector<std::string> list;
    std::map<std::string, std::function<Json::Value(const std::string&)>> pipeline;

    template<typename ftor>
    void installPipeline(std::string name, ftor && handler)
    {
        pipeline.insert({
                                   std::move(name),
                                   std::forward<ftor>(handler)
                           });
    }
};




#endif //TRADER_ALGOCONTEXT_H


