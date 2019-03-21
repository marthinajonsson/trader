//
// Created by mjonsson on 2/14/19.
//

#ifndef TRADER_DEEPLEARNING_H
#define TRADER_DEEPLEARNING_H

#include <array>
#include <vector>
#include <boost/array.hpp>
#include "Exceptions.h"


class DeepLearning {
public:
    DeepLearning() = default;

    ~DeepLearning() = default;

    void run();
private:
    boost::array<int,2> weights;

    std::vector<double> mseHist;
    float learningRate = 0.01;

    boost::array<double,200> GetHistoricalPrices();
    boost::array<double,1> predict(boost::array<double,200> input, boost::array<int,2> weights);
    boost::array<int, 2> updateWeights (boost::array<int,2> weights, boost::array<int,2> slope);

    double getError(double &output, double &target);
    double getMSE(std::array<int,2>&, int&);


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

        for (int i = 0; i < sizeof(errors); i++)
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
