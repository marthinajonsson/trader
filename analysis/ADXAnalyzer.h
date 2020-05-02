//
// Created by mjonsson on 8/23/19.
//

#ifndef TRADER_ADXANALYZER_H
#define TRADER_ADXANALYZER_H

#include "Analyzer.h"


//
//0-25	Absent or Weak Trend
//25-50	Strong Trend
//50-75	Very Strong Trend
//75-100	Extremely Strong Trend

class ADXAnalyzer : Analyzer {
private:
    static const int WEAK_TREND_MIN = 0;
    static const int STRONG_TREND_MIN = 25;
    static const int VERY_STRONG_MIN = 50;
    static const int EXTREMLY_STRONG_TREND_MIN = 75;
public:
    void process() override;
};
#endif //TRADER_ADXANALYZER_H
