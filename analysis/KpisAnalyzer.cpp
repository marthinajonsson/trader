//
// Created by mjonsson on 5/2/20.
//

#include <CSVWriter.h>
#include "KpisAnalyzer.h"

void KpisAnalyzer::process() {
    IO::CSVWriter csv("Kpislistv1.csv", '\n');
    auto lines = csv.getAllLines();
}
