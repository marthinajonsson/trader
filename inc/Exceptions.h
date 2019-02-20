//
// Created by mjonsson on 2/15/19.
//

#ifndef TRADER_EXCEPTIONS_H
#define TRADER_EXCEPTIONS_H


#include <iostream>
#include <string>


enum RETcode{
    SUCCESS = 0,
    ERROR = -1
};


class DeepLearningImplException : public std::logic_error
{
public:
    DeepLearningImplException(const int error, const char *msg) :  std::logic_error(msg) { };
};

class MeanRevImplException : public std::logic_error
{
public:
    MeanRevImplException(const int error, const char* msg) : std::logic_error(msg) { };
};

class SentimentImplException : public std::logic_error
{
public:
    SentimentImplException(const int error, const char* msg) : std::logic_error(msg) { };
};


#endif //TRADER_EXCEPTIONS_H
