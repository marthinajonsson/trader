//
// Created by mjonsson on 8/24/19.
//

#include <iostream>
#include "Interests.h"

vector<string> Interests::getInterests() {
    return read();
}

void Interests::addInterest(string &ticker) {
    IO::CSVWriter csv("../data/Interests.csv", ',');
    csv.addDatainRow(ticker.begin(), ticker.end());
}

ERR_CODE Interests::removeInterest(int &num) {
    IO::CSVWriter csv("../data/Interests.csv", ',');
    return (ERR_CODE)csv.deleteRow(num);
}

void Interests::printInterests()
{
    vector<string> result = read();
    for (const string &s : result) {
        std::cout << s << std::endl;
    }
}

vector<string> Interests::read()
{
    IO::CSVWriter csv("../data/Interests.csv", ',');
    return csv.getAllLines();
}

