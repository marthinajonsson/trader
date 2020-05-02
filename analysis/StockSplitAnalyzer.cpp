//
// Created by mjonsson on 5/2/20.
//

#include <CSVWriter.h>
#include "StockSplitAnalyzer.h"

void StockSplitAnalyzer::process() {
    IO::CSVWriter csv("StockSplitsv1.csv", '\n');
    auto lines = csv.getAllLines();
}
