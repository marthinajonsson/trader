//
// Created by mjonsson on 8/23/19.
//

#ifndef TRADER_PROCESSHANDLER_H
#define TRADER_PROCESSHANDLER_H

#include "Observer.h"

class ProcessHandler : public Observer {
private:

public:
    ProcessHandler()= default;
    ~ProcessHandler()= default;
    ProcessHandler(ProcessHandler const&) = delete;
    void operator=(ProcessHandler const&) = delete;

    void update(string event, Subject *subject) override;

};
#endif //TRADER_PROCESSHANDLER_H
