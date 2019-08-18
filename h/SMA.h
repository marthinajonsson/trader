//
// Created by mjonsson on 8/18/19.
//

#ifndef TRADER_SMA_H
#define TRADER_SMA_H
class SMA {
private:
    SMA()= default;
    ~SMA()= default;

public:
    static SMA& getInstance();
    SMA(SMA const&) = delete;
    void operator=(SMA const&) = delete;

    void run();
};
#endif //TRADER_SMA_H
