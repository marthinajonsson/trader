//
// Created by mjonsson on 10/12/19.
//

#ifndef TRADER_RSI_H
#define TRADER_RSI_H


#include <Subject.h>
#include <Algorithm.h>

class RSI : Algorithm, Subject {
private:
    RSI()= default;
    ~RSI()= default;
public:
    static RSI& getInstance();
    RSI(RSI const&) = delete;
    void operator=(RSI const&) = delete;

    void run() override;
};



#endif //TRADER_RSI_H
