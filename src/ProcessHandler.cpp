//
// Created by mjonsson on 8/23/19.
//

#include "ProcessHandler.h"
#include "ADXAnalyzer.h"
#include "SMAAnalyzer.h"

#include <iostream>

void ProcessHandler::update(string event, Subject *subject) {
    std::cout << "Registered " << event << std::endl;

    if (event == ALGORITHM::ADX) {
        ADXAnalyzer analyzer;
        analyzer.process();
    }
    else if (event == ALGORITHM::SMA) {
        SMAAnalyzer analyzer;
        analyzer.process();
    }
}

