//
// Created by mjonsson on 8/8/19.
//

#ifndef TRADER_ADX_H
#define TRADER_ADX_H
//
//0-25	Absent or Weak Trend
//25-50	Strong Trend
//50-75	Very Strong Trend
//75-100	Extremely Strong Trend
class ADX {
private:
    ADX()= default;
    ~ADX()= default;
    static const int WEAK_TREND_MIN = 0;
    static const int STRONG_TREND_MIN = 25;
    static const int VERY_STRONG_MIN = 50;
    static const int EXTREMLY_STRONG_TREND_MIN = 75;
public:
    static ADX& getInstance();
    ADX(ADX const&) = delete;
    void operator=(ADX const&) = delete;

    static void run();
};

#endif //TRADER_ADX_H
