//
// Created by mjonsson on 4/30/20.
//

#include <Client.h>
#include "IInstrumentsApi.h"
#include "Exceptions.h"
#include "IBorsdata.h"
#include <boost/foreach.hpp>

class InstrumentsApi : IInstrumentsApi, IBorsdata {
public:

    InstrumentUpdatedRespV1 Instrumentsupdatedv1 (string authKey) override {
        // verify the required parameter 'authKey' is set
        if (authKey.empty()) throw ConnectionExceptions(400, "Missing required parameter 'authKey' when calling Instrumentsupdatedv1");

        string url = getBaseUrl();
        url += "/v1/instruments/updated";
        addToken(url);
        ptree respData;
        Client::sendRequest(respData, url);
        auto obj = respData.get_child("instruments");
        BOOST_ASSERT(!obj.empty());

        InstrumentUpdatedRespV1 resultResp;
        BOOST_FOREACH(boost::property_tree::ptree::value_type &val, obj)
        {
            InstrumentUpdatedV1 result;
            result.insid = val.second.get<long>("insId");
            result.updateAt = val.second.get<string>("updatedAt");
            resultResp.instrumentUpdated.emplace_back(result);
        }
        return resultResp;
    }

    InstrumentRespV1 Instrumentsv1 (string authKey) override {
        // verify the required parameter 'authKey' is set
        if (authKey.empty()) throw ConnectionExceptions(400, "Missing required parameter 'authKey' when calling Instrumentsv1");

        string url = getBaseUrl();
        url += "/v1/instruments";
        addToken(url);
        ptree respData;
        Client::sendRequest(respData, url);
        auto obj = respData.get_child("instruments");
        BOOST_ASSERT(!obj.empty());

        InstrumentRespV1 resultResp;
        BOOST_FOREACH(boost::property_tree::ptree::value_type &val, obj)
        {
            InstrumentV1 result;
            result.insid = val.second.get<long>("insId");
            result.name = val.second.get<string>("name");
            result.urlName = val.second.get<string>("urlName");
            result.instrument = val.second.get<int>("instrument");
            result.isin = val.second.get<string>("isin");
            result.ticker = val.second.get<string>("ticker");
            result.sectorId = val.second.get<long>("sectorId");
            result.marketId = val.second.get<long>("marketId");
            result.branchId = val.second.get<long>("branchId");
            result.countryId = val.second.get<long>("countryId");
            result.date = val.second.get<string>("date");
            resultResp.instruments.emplace_back(result);
        }
        return resultResp;
    }

};
