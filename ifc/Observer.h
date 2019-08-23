//
// Created by mjonsson on 8/23/19.
//

#ifndef TRADER_OBSERVER_H
#define TRADER_OBSERVER_H

#include <Util.h>

class Subject;

class Observer {

public:

    Observer() = default;

    ~Observer() = default;

    virtual void update(string event, Subject *subject) = 0;

};

#endif //TRADER_OBSERVER_H
