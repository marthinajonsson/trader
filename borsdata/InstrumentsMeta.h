//
// Created by mjonsson on 5/1/20.
//

#ifndef TRADER_INSTRUMENTSMETA_H
#define TRADER_INSTRUMENTSMETA_H

#include "Algorithm.h"

class InstrumentsMeta : Algorithm, Subject {
private:
    InstrumentsMeta()= default;
    ~InstrumentsMeta()= default;
public:
    static InstrumentsMeta& getInstance();
    InstrumentsMeta(InstrumentsMeta const&) = delete;
    void operator=(InstrumentsMeta const&) = delete;

    void run() override;
};

#endif //TRADER_INSTRUMENTSMETA_H
