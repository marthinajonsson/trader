//
// Created by mjonsson on 2/14/19.
//

#ifndef TRADER_DEEPLEARNING_H
#define TRADER_DEEPLEARNING_H

#include <array>
#include <vector>
#include "Exceptions.h"


class DeepLearning {
public:
    DeepLearning() {
    };

    ~DeepLearning() {
    };

    void errorHandler(RETcode &retCode) const;

    void run();
private:
    std::array<int,2> input;
    std::array<int,2> prediction;
    std::array<int,2> weights;

    std::vector<double> mseHist;
    float learningRate = 0.01;

    std::array<int,1> predict(std::array<int,2>& input, std::array<int,2> weights);
    std::array<double, 2> updateWeights (std::array<int,2> weights, std::array<int,2> slope);

    double getError(int &output, int &target);
    double getMSE(std::array<int,2>&, int&);

};

#endif //TRADER_DEEPLEARNING_H
