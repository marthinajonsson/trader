//
// Created by mjonsson on 8/8/19.
//

#ifndef TRADER_ADX_H
#define TRADER_ADX_H

#include "Algorithm.h"

class ADX : Algorithm, Subject {
private:
    ADX()= default;
    ~ADX()= default;
public:
    static ADX& getInstance();
    ADX(ADX const&) = delete;
    void operator=(ADX const&) = delete;

    void run() override;
};

#endif //TRADER_ADX_H
