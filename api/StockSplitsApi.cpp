//
// Created by mjonsson on 5/1/20.
//

#include "IBorsdata.h"
#include "IStockSplitsApi.h"
#include <Client.h>
#include "Exceptions.h"
#include <boost/foreach.hpp>

class StockSplitsApi : IStockSplitsApi, IBorsdata {
public:

    /// <summary>
    /// Returns Stock Splits for all Instruments. Max 1 Year Returns Stock Splits for all Instruments. Max 1 Year
    /// </summary>
    /// <param name="authKey">API Authentication Key</param>
    /// <returns>StockSplitRespV1</returns>
    StockSplitRespV1 StockSplitsv1 (string authKey) override {

        // verify the required parameter 'authKey' is set
        if (authKey.empty())
            throw ConnectionExceptions(400, "Missing required parameter 'authKey' when calling StockSplitsv1");


        string url = getBaseUrl();
        url += "/v1/instruments/StockSplits";
        addToken(url);
        ptree respData;
        Client::sendRequest(respData, url);
        auto obj = respData.get_child("stockSplitList");
        BOOST_ASSERT(!obj.empty());
        StockSplitRespV1 resultResp;
        BOOST_FOREACH(boost::property_tree::ptree::value_type &val, obj)
        {
            StockSplitV1 result;
            result.instrumentId = val.second.get<long>("instrumentId");
            result.splitDate = val.second.get<string>("splitDate");
            result.splitRate = val.second.get<string>("ratio");
            resultResp.stockSplitList.emplace_back(result);
        }
        return resultResp;
    }
};