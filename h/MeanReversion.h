//
// Created by mjonsson on 2/16/19.
//

#ifndef TRADER_MEANREVERSION_H
#define TRADER_MEANREVERSION_H

#include "Subject.h"
#include "Algorithm.h"
#include <mutex>

class MeanReversion : Algorithm, Subject {
private:
    MeanReversion()= default;
    ~MeanReversion()= default;
public:
    static MeanReversion& getInstance();
    MeanReversion(MeanReversion const&) = delete;
    void operator=(MeanReversion const&) = delete;

    void run();
};



#endif //TRADER_MEANREVERSION_H
