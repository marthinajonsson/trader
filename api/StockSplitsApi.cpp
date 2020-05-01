//
// Created by mjonsson on 5/1/20.
//

#include "StockSplitsApi.h"
#include <Client.h>
#include <boost/foreach.hpp>


/// <summary>
/// Returns Stock Splits for all Instruments. Max 1 Year Returns Stock Splits for all Instruments. Max 1 Year
/// </summary>
/// <returns>StockSplitRespV1</returns>
StockSplitRespV1 StockSplitsApi::StockSplitsv1 () {
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
