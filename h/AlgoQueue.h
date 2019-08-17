//
// Created by mjonsson on 2/16/19.
//

#ifndef TRADER_ALGOQUEUE_H
#define TRADER_ALGOQUEUE_H


#include "AlgoDispatcher.h"

#include <thread>
#include <queue>
#include <mutex>
#include <future>
#include <iostream>

typedef std::function<void()> Operation;

class AlgoQueue {
private:
    std::mutex qlock;
    std::queue<Operation> ops_queue;
    std::condition_variable empty;
    AlgoDispatcher dispatcher;
public:
    AlgoQueue() = default;
    ~AlgoQueue() = default;

    void put(string opName, string opParam) {
        std::lock_guard<std::mutex> guard(qlock);
        Operation op = dispatcher.set(opName);
        ops_queue.push(op);
        empty.notify_one();
    }

    Operation take() {
        std::unique_lock<std::mutex> lock(qlock);
        empty.wait(lock, [&]{ return !ops_queue.empty(); });

        Operation op = ops_queue.front();
        ops_queue.pop();
        return op;
    }
};

#endif //TRADER_ALGOQUEUE_H
