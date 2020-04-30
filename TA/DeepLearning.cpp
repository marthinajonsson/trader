//
// Created by mjonsson on 2/15/19.
//

#include "DeepLearning.h"


array_b<double,200> DeepLearning::GetHistoricalPrices()
{
    array_b<double, 200> prices{};
    auto historicalData = IEX::fetch("AAPL", IEX::INDICATOR::HISTORICAL_PRICES::HIST_PRICE_SIX_MONTH);
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

    Json::Value data = IEX::fetch("AAPL", IEX::INDICATOR::STATS::STATS, IEX::INDICATOR::STATS::KEY::DAY_200_MOV_AVG);
    int i = 0;
    while (i < data.size()) {
        movingAverage[i] = data[i].asDouble();
        i++;
    }
    double target = closingPrices[0] *0.10;

    array_b<double, 200> maBoost{};
    for(auto &d : movingAverage) {
        maBoost.fill(d);
    }
    auto predictions = predict(maBoost, weights);
    double p_front = predictions[0];
    double err = getError(p_front, target);

    if (err != 0) {
        // do something to repeat
    }
}

array_b<int, 2> DeepLearning::updateWeights(array_b<int,2> weights, array_b<int,2> slope) {
    array_b<int, 2> newWeights{};
    for(unsigned long index = 0; index < weights.size(); index++) {
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

array_b<double,1> DeepLearning::predict(array_b<double,200> input, array_b<int,2> weights) {

    array_b<double,1> prediction {};
    auto weight_p = weights.begin();
    for (double value : input) {
        int weight = *weight_p;
        double predValue = value * weight;
        prediction.fill(predValue);
    }
    return prediction;
}

double DeepLearning::getMSE(array_b<int,2>& input, int& target) {
    double mse = 0;
    return mse;
}
