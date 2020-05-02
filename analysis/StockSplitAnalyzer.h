//
// Created by mjonsson on 5/2/20.
//

#ifndef TRADER_STOCKSPLITANALYZER_H
#define TRADER_STOCKSPLITANALYZER_H


#include <Analyzer.h>

class StockSplitAnalyzer : Analyzer {
private:
public:
    void process() override;
};

#endif //TRADER_STOCKSPLITANALYZER_H
