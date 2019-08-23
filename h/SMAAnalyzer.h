//
// Created by mjonsson on 8/23/19.
//

#ifndef TRADER_SMAANALYZER_H
#define TRADER_SMAANALYZER_H

#include "Analyzer.h"

class SMAAnalyzer : Analyzer {
private:
    static const int WEAK_TREND_MIN = 0;
    static const int STRONG_TREND_MIN = 25;
    static const int VERY_STRONG_MIN = 50;
    static const int EXTREMLY_STRONG_TREND_MIN = 75;
public:
    void process() override;
};

#endif //TRADER_SMAANALYZER_H
