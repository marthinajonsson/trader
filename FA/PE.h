//
// Created by mjonsson on 10/12/19.
//

#ifndef TRADER_PE_H
#define TRADER_PE_H

#include <Subject.h>
#include <Algorithm.h>

class PE : Algorithm, Subject {
private:
    PE()= default;
    ~PE()= default;
public:
    static PE& getInstance();
    PE(PE const&) = delete;
    void operator=(PE const&) = delete;

    void run() override;
};



#endif //TRADER_PE_H
