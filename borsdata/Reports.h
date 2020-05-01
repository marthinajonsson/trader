//
// Created by mjonsson on 5/1/20.
//

#ifndef TRADER_REPORTS_H
#define TRADER_REPORTS_H


#include "Algorithm.h"

class Reports : Algorithm, Subject {
private:
    Reports()= default;
    ~Reports()= default;
public:
    static Reports& getInstance();
    Reports(Reports const&) = delete;
    void operator=(Reports const&) = delete;

    void run() override;
};


#endif //TRADER_REPORTS_H
