//
// Created by mjonsson on 5/1/20.
//

#ifndef TRADER_INSTRUMENTSAPI_H
#define TRADER_INSTRUMENTSAPI_H

#include "IInstrumentsApi.h"
#include "IBorsdata.h"

class InstrumentsApi : IInstrumentsApi, IBorsdata {
public:
    InstrumentUpdatedRespV1 Instrumentsupdatedv1 () override;
    InstrumentRespV1 Instrumentsv1 () override;
};

#endif //TRADER_INSTRUMENTSAPI_H
