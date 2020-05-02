//
// Created by mjonsson on 5/2/20.
//

#include <CSVWriter.h>
#include "InstrumentMetaAnalyzer.h"

void InstrumentMetaAnalyzer::process() {
    IO::CSVWriter csv("Branchesv1.csv", '\n');
    auto lines = csv.getAllLines();

}
