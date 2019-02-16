//
// Created by mjonsson on 2/14/19.
//

#ifndef TRADER_ACTIVEALGORITHM_H
#define TRADER_ACTIVEALGORITHM_H

#include "AlgoQueue.h"
#include "json/json.h"
#include "IEX.h"
#include "Util.h"

#include <string>
#include <thread>
#include <queue>
#include <mutex>
#include <future>
#include <iostream>


namespace Trader {


/*! \class ActiveAlgorithm
 *  \implements ActiveObject
 *  \namespace Trader
 *  \todo finish
 *  \brief Used by all algorithms
 */
    class ActiveAlgorithm {
    private:

        std::string val;
        AlgoQueue queue;
        std::atomic<bool> done;
        std::thread *runnable;

    public:
        ActiveAlgorithm() : val(0), done(false) {
            runnable = new std::thread(&ActiveAlgorithm::run, this);
        }
        ~ActiveAlgorithm() { runnable->join(); }

        std::string getVal() { return val; }

        void registerWork(std::string algorithm) {
            val = algorithm;
            queue.put(algorithm);
        }

        void run() {
            while (!done) {
                queue.take()();
            }
        }
    };
}


#endif //TRADER_ACTIVEALGORITHM_H


