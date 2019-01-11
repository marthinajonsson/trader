//
// Created by mjonsson on 1/11/19.
//

#ifndef TRADER_COMPANYINFO_H
#define TRADER_COMPANYINFO_H

#include <ifc/ICommand.h>


class Command : ICommand
{
public:
    Command()= default;
    ~Command() = default;

    void Execute(){}

};
#endif //TRADER_COMPANYINFO_H
