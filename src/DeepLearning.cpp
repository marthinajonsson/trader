//
// Created by mjonsson on 2/15/19.
//
#include <ta-lib/ta_func.h>
#include "DeepLearning.h"
#include <boost/array.hpp>
#include <IEX.h>


boost::array<double,200> DeepLearning::GetHistoricalPrices()
{
    boost::array<double, 200> prices{};
    auto historicalData = IEX::stock::chart("AAPL", "6m");
    for (auto day : historicalData) {
        double price = day["close"].asDouble();
        prices.fill(price);
    }

    return prices;
}

void DeepLearning::run() {

    auto prices = GetHistoricalPrices();
    const double* closingPrices = prices.data();

    double movingAverage[200]{};
    int* idx0 = nullptr, *idxLast = nullptr;

    TA_RetCode result_MA = TA_MA(0,199, closingPrices, 200, TA_MAType_SMA, idx0, idxLast, movingAverage);

    if(result_MA != TA_SUCCESS) {
        errorHandler(RETcode::ERROR);
    }

    double target = closingPrices[0] *0.10;

    boost::array<double, 200> maBoost{};
    for(auto &d : movingAverage) {
        maBoost.fill(d);
    }
    auto predictions = predict(maBoost, weights);
    double p_front = predictions[0];
    double err = getError(p_front, target);

    while(err != 0) {
        // do something to repeat
    }
}

boost::array<int, 2> DeepLearning::updateWeights(boost::array<int,2> weights, boost::array<int,2> slope) {
    boost::array<int, 2> newWeights{};
    for(auto index = 0; index < weights.size(); index++) {
        double result = weights[index] - learningRate * slope[index];
        newWeights.fill(result);
    }
    return newWeights;
}

double DeepLearning::getError(double &output, double &target) {

    if(target > output) {
        return target - output;
    }
    return output - target;
}

boost::array<double,1> DeepLearning::predict(boost::array<double,200> input, boost::array<int,2> weights) {

    boost::array<double,1> prediction {};
    auto weight_p = weights.begin();
    for (double value : input) {
        int weight = *weight_p;
        double predValue = value * weight;
        prediction.fill(predValue);
    }
    return prediction;
}

double DeepLearning::getMSE(std::array<int,2>& input, int& target) {
    double mse = 0;
    return mse;
}
