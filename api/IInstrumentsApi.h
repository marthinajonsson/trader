//
// Created by mjonsson on 4/30/20.
//

#ifndef TRADER_IINSTRUMENTSAPI_H
#define TRADER_IINSTRUMENTSAPI_H

#include <Util.h>
#include <InstrumentRespV1.h>
#include <InstrumentUpdatedRespV1.h>

class IInstrumentsApi {
protected:
    /// <summary>
    /// Returns all Updated Instruments Returns all Updated Instruments
    /// </summary>
    /// <returns>InstrumentUpdatedRespV1</returns>
    virtual InstrumentUpdatedRespV1 Instrumentsupdatedv1 () = 0;

    /// <summary>
    /// Returns all Instruments Returns all Instruments
    /// </summary>
    /// <returns>InstrumentRespV1</returns>
    virtual InstrumentRespV1 Instrumentsv1 () = 0;
};

#endif //TRADER_IINSTRUMENTSAPI_H
