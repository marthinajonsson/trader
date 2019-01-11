//
// Created by mjonsson on 1/11/19.
//

#ifndef TRADER_ICOMMAND_H
#define TRADER_ICOMMAND_H

class ICommand
{
public:
    virtual void Execute() = 0;
};

#endif //TRADER_ICOMMAND_H
