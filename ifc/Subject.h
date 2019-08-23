//
// Created by mjonsson on 8/23/19.
//

#ifndef TRADER_SUBJECT_H
#define TRADER_SUBJECT_H

#include "Util.h"
#include <map>
#include <vector>

class Observer;

class Subject
{
protected:
    std::map<string , std::vector<Observer *> > _registryMap;
public:

    void registerObserver(string event, Observer *observer);
    void removeObserver(Observer *observer);
    void notifyObservers(string event);
};
#endif //TRADER_SUBJECT_H
