//
// Created by mjonsson on 2/14/19.
//

#ifndef TRADER_TALIB_H
#define TRADER_TALIB_H

#include <ta_libc.h>
#include "Exceptions.h"

class TechnicalInvest {
public:
    TechnicalInvest() {
        TA_Initialize();
    };

    ~TechnicalInvest() {
        TA_Shutdown();
    };

    void errorHandler(TA_RetCode &retCode) const;

private:
};

#endif //TRADER_TALIB_H
