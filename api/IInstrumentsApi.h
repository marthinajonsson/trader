//
// Created by mjonsson on 4/30/20.
//

#ifndef TRADER_IINSTRUMENTSAPI_H
#define TRADER_IINSTRUMENTSAPI_H

#include <Util.h>
#include <InstrumentRespV1.h>
#include <InstrumentUpdatedRespV1.h>

class IInstrumentsApi {
public:
    /// <summary>
    /// Returns all Updated Instruments Returns all Updated Instruments
    /// </summary>
    /// <param name="authKey">API Authentication Key</param>
    /// <returns>InstrumentUpdatedRespV1</returns>
    virtual InstrumentUpdatedRespV1 Instrumentsupdatedv1 (string authKey) = 0;

    /// <summary>
    /// Returns all Instruments Returns all Instruments
    /// </summary>
    /// <param name="authKey">API Authentication Key</param>
    /// <returns>InstrumentRespV1</returns>
    virtual InstrumentRespV1 Instrumentsv1 (string authKey) = 0;
};

#endif //TRADER_IINSTRUMENTSAPI_H
