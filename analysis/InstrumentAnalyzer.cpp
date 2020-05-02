//
// Created by mjonsson on 5/2/20.
//

#include <CSVWriter.h>
#include "InstrumentAnalyzer.h"

void InstrumentAnalyzer::process() {

    IO::CSVWriter csv("Instrumentsv1.csv", '\n');
    auto lines = csv.getAllLines();

    IO::CSVWriter csv2("Instrumentsupdatedv1.csv", '\n');
    auto lines2 = csv2.getAllLines();
}
