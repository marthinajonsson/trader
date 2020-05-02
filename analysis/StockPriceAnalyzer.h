//
// Created by mjonsson on 5/2/20.
//

#ifndef TRADER_STOCKPRICEANALYZER_H
#define TRADER_STOCKPRICEANALYZER_H


#include <Analyzer.h>

class StockPriceAnalyzer : Analyzer {
private:
public:
    void process() override;
};


#endif //TRADER_STOCKPRICEANALYZER_H
