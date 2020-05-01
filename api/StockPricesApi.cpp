//
// Created by mjonsson on 5/1/20.
//

#include <Client.h>
#include "IBorsdata.h"
#include "IStockPricesApi.h"
#include <boost/foreach.hpp>
#include "Exceptions.h"

class StockPricesApi : IStockPricesApi, IBorsdata {
    bool replace(string& str, const string& from, const string& to) {
        size_t start_pos = str.find(from);
        if(start_pos == string::npos)
            return false;
        str.replace(start_pos, from.length(), to);
        return true;
    }
public:

    /// <summary>
    /// Returns Last StockPrices for all Instruments. Returns Last StockPrice for all Instrument
    /// </summary>
    /// <param name="authKey">API Authentication Key</param>
    /// <param name="version">The requested API version</param>
    /// <returns>StockPricesLastRespV1</returns>
    StockPricesLastRespV1 Stockpriceslastv1 (string authKey, string version) override {

        // verify the required parameter 'authKey' is set
        if (authKey.empty())
            throw ConnectionExceptions(400, "Missing required parameter 'authKey' when calling Stockpriceslastv1");

        // verify the required parameter 'version' is set
        if (version.empty())
            throw ConnectionExceptions(400, "Missing required parameter 'version' when calling Stockpriceslastv1");

        string url = getBaseUrl();
        url +=  "/v1/instruments/stockprices/last";
        addToken(url);
        ptree respData;
        Client::sendRequest(respData, url);

        StockPricesLastRespV1 resultResp;
        auto obj = respData.get_child("stockPricesList");
        BOOST_ASSERT(!obj.empty());
        BOOST_FOREACH(boost::property_tree::ptree::value_type &val, obj)
        {
            StockPriceV1 result;
            result.c = val.second.get<double>("c");
            result.d = val.second.get<string>("d");
            result.h = val.second.get<double>("h");
            result.l = val.second.get<double>("l");
            resultResp.instrument = val.second.get<double>("i");
            result.o = val.second.get<double>("o");
            result.v = val.second.get<double>("v");
            resultResp.stockPricesList.emplace_back(result);
        }
        return resultResp;
    }

    /// <summary>
    /// Returns StockPrice for Instrument. Max 10 years, if no time filters provided. Returns StockPrice for Instrument
    /// </summary>
    /// <param name="insid">Instrument Id</param>
    /// <param name="authKey">API Authentication Key</param>
    /// <param name="from">Date From</param>
    /// <param name="to">Date To</param>
    /// <returns>StockPricesRespV1</returns>
    StockPricesRespV1 Stockpricesv1 (int insid, string authKey, string from, string to) override {

        // verify the required parameter 'insid' is set
        if (insid == 0) throw ConnectionExceptions(400, "Missing required parameter 'insid' when calling Stockpricesv1");

        // verify the required parameter 'authKey' is set
        if (authKey.empty())
            throw ConnectionExceptions(400, "Missing required parameter 'authKey' when calling Stockpricesv1");

        string url = getBaseUrl();
        url +=  "/v1/instruments/{insid}/stockprices";
        replace(url, "{insid}", std::to_string(insid));
        addToken(url);
        ptree respData;
        Client::sendRequest(respData, url);

        StockPricesRespV1 resultResp;
        resultResp.instrument = respData.get<long>("instrument");
        auto obj = respData.get_child("stockPricesList");
        BOOST_ASSERT(!obj.empty());
        BOOST_FOREACH(boost::property_tree::ptree::value_type &val, obj)
        {
            StockPriceV1 result;
            result.c = val.second.get<double>("c");
            result.d = val.second.get<string>("d");
            result.h = val.second.get<double>("h");
            result.l = val.second.get<double>("l");
            result.o = val.second.get<double>("o");
            result.v = val.second.get<double>("v");
            resultResp.stockPricesList.emplace_back(result);
        }
        return resultResp;
    }
};