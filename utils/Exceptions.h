//
// Created by mjonsson on 2/15/19.
//

#ifndef TRADER_EXCEPTIONS_H
#define TRADER_EXCEPTIONS_H


#include <iostream>
#include <string>

class AlgorithmException : public std::logic_error
{
public:
    AlgorithmException(const int error, const char *msg) :  std::logic_error(msg) { };
};

class ConnectionExceptions : public std::logic_error
{
public:
    ConnectionExceptions(const int error, const char* msg) : std::logic_error(msg) { };
};

class GenericImplException : public std::logic_error
{
public:
    GenericImplException(const int error, const char* msg) : std::logic_error(msg) { };
};


#endif //TRADER_EXCEPTIONS_H
