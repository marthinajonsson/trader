//
// Created by mjonsson on 2/14/19.
//

#ifndef TRADER_DEEPLEARNING_H
#define TRADER_DEEPLEARNING_H

#include "Exceptions.h"
#include "UniBit.h"
#include "Util.h"

class DeepLearning {
public:
    DeepLearning() = default;

    ~DeepLearning() = default;

    void run();
private:
    array_b<int,2> weights {0,0};

    vector<double> mseHist;
    constexpr static const float learningRate = 0.01;

    static array_b<double,200> GetHistoricalPrices();
    static array_b<double,1> predict(array_b<double,200> input, array_b<int,2> weights);
    static array_b<int, 2> updateWeights (array_b<int,2> weights, array_b<int,2> slope);

    static double getError(double &output, double &target);
    static double getMSE(array_b<int,2>&, int&);


    void errorHandler(RETcode &&retCode) const {

        if (retCode == SUCCESS) {
            return;
        }

        const static struct errors {
            RETcode code;
            const char *msg;
        } errors[] = {
                {RETcode::ERROR, "Lib not initialized"},
        };

        for (unsigned long i = 0; i < sizeof(errors); i++)
        {
            if (errors[i].code == retCode)
            {
                throw DeepLearningImplException(errors[i].code, errors[i].msg);
            }
        }

        throw DeepLearningImplException(retCode, "unknown_error");
    }
};

#endif //TRADER_DEEPLEARNING_H
