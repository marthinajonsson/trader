//
// Created by mjonsson on 5/2/20.
//

#include <CSVWriter.h>
#include "StockPriceAnalyzer.h"

void StockPriceAnalyzer::process() {

    IO::CSVWriter csv("Stockpricesv1.csv", '\n');
    auto lines = csv.getAllLines();
}
