//
// Created by mjonsson on 5/1/20.
//

#ifndef TRADER_INSTRUMENTS_H
#define TRADER_INSTRUMENTS_H

#include "Algorithm.h"

class Instruments : Algorithm, Subject {
private:
    Instruments()= default;
    ~Instruments()= default;
public:
    static Instruments& getInstance();
    Instruments(Instruments const&) = delete;
    void operator=(Instruments const&) = delete;

    void run() override;
};


#endif //TRADER_INSTRUMENTS_H
