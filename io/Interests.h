//
// Created by mjonsson on 8/24/19.
//

#ifndef TRADER_INTERESTS_H
#define TRADER_INTERESTS_H

#include "CSVWriter.h"
#include "Util.h"

class Interests {
private:
    vector<string> read();
public:
    vector<string> getInterests();
    void addInterest(string&);
    ERR_CODE removeInterest(int&);
    void printInterests();
};
#endif //TRADER_INTERESTS_H
