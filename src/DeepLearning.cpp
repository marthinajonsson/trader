//
// Created by mjonsson on 2/15/19.
//

#include "DeepLearning.h"

void DeepLearning::errorHandler(RETcode &retCode) const {

    if (retCode == SUCCESS) {
        return;
    }

    const static struct errors {
        RETcode code;
        const char *msg;
    } errors[] = {
            {RETcode::ERROR,        "Lib not initialized"},
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

void DeepLearning::run() {
    std::array<int, 2> input{1, 3};
    int target = 10;
//    std::array<int,1> modelOutput;

    std::array<int,1> result = predict(input, weights);

    double err = getError(result.front(), target);

    while(err != 0) {

    }
}

double DeepLearning::getError(int &output, int &target){

    if(target > output) {
        return target - output;
    }
    return output - target;
}

std::array<int,1> DeepLearning::predict(std::array<int,2>& input, std::array<int,2> weights) {

    std::array<int,1> prediction;
    std::array<int,2>::const_iterator weight_p = weights.begin();
    for(std::array<int,2>::const_iterator it = input.begin(); it != input.end(); it++) {
        int value = *it;
        int weight = *weight_p;
        int predValue = value * weight;
        prediction.fill(predValue);
    }
    return prediction;
}

double DeepLearning::getMSE(std::array<int,2>& input, int& target) {
    
    double mse = 0;
    return mse;
}

std::array<double, 2> DeepLearning::updateWeights(std::array<int,2> weights, std::array<int,2> slope) {
    std::array<double, 2> newWeights;
    for(auto index = 0; index < weights.size(); index++) {
        double result = weights[index] - learningRate * slope[index];
        newWeights.fill(result);
    }
    return newWeights;
}
