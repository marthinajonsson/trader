//
// Created by mjonsson on 5/1/20.
//

#ifndef TRADER_KPIS_H
#define TRADER_KPIS_H

#include "Algorithm.h"

class Kpis : Algorithm, Subject {
private:
    Kpis()= default;
    ~Kpis()= default;
public:
    static Kpis& getInstance();
    Kpis(Kpis const&) = delete;
    void operator=(Kpis const&) = delete;

    void run() override;
};

#endif //TRADER_KPIS_H
