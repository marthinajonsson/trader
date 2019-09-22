//
// Created by mjonsson on 8/18/19.
//

#ifndef TRADER_SMA_H
#define TRADER_SMA_H

#include "Algorithm.h"

class SMA  : Algorithm, Subject {
private:
    SMA()= default;
    ~SMA()= default;
public:
    static SMA& getInstance();
    SMA(SMA const&) = delete;
    void operator=(SMA const&) = delete;

    void run() override;
};
#endif //TRADER_SMA_H
