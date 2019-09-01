//
// Created by mjonsson on 8/23/19.
//

#ifndef TRADER_SMAANALYZER_H
#define TRADER_SMAANALYZER_H

#include "Analyzer.h"

class SMAAnalyzer : Analyzer {
private:
public:
    void process() override;
};

#endif //TRADER_SMAANALYZER_H
