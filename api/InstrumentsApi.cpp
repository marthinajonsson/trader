//
// Created by mjonsson on 4/30/20.
//

#include <Client.h>
#include "IInstrumentsApi.h"
#include "Exceptions.h"
#include "IBorsdata.h"

class InstrumentsApi : IInstrumentsApi, IBorsdata {
public:

    /*
 * InstrumentUpdatedV1{
    insId	integer($int64)
    updatedAt	string($date-time)
    }
 * */
    InstrumentUpdatedRespV1 Instrumentsupdatedv1 (string authKey) override {
        // verify the required parameter 'authKey' is set
        if (authKey.empty()) throw ConnectionExceptions(400, "Missing required parameter 'authKey' when calling Instrumentsupdatedv1");

        string url = getBaseUrl();
        url += "/v1/instruments/updated";
        addToken(url);
        //Client::getInstance().sendRequest(respData, url);
    }

    InstrumentRespV1 Instrumentsv1 (string authKey) override {
        // verify the required parameter 'authKey' is set
        if (authKey.empty()) throw ConnectionExceptions(400, "Missing required parameter 'authKey' when calling Instrumentsv1");

        string url = getBaseUrl();
        url += "/v1/instruments";
        addToken(url);
    }

};