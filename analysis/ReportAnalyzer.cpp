//
// Created by mjonsson on 5/2/20.
//

#include <CSVWriter.h>
#include "ReportAnalyzer.h"

void ReportAnalyzer::process() {

    IO::CSVWriter csv("Reportsv1.csv", '\n');
    auto lines = csv.getAllLines();
}
