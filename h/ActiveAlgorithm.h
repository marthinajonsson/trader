//
// Created by mjonsson on 2/14/19.
//

#ifndef TRADER_ACTIVEALGORITHM_H
#define TRADER_ACTIVEALGORITHM_H

#include "AlgoQueue.h"
#include "jsoncpp/json/json.h"
#include "IEX.h"
#include "Util.h"

#include <thread>
#include <queue>
#include <mutex>
#include <future>

namespace Trader {


/*! \class ActiveAlgorithm
 *  \implements ActiveObject pattern
 *  \brief Used by all algorithms
 */
    class ActiveAlgorithm {
    private:

        string val;
        AlgoQueue queue;
        std::atomic<bool> done;
        std::thread *runnable;

    public:
        ActiveAlgorithm() : val(""), done(false) {
            runnable = new std::thread(&ActiveAlgorithm::run, this);
        }
        ~ActiveAlgorithm() { runnable->join(); }

        string getVal() { return val; }

        void endWork() { done = true; }

        void registerWork(const string algorithm) {
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


