//
// Created by mjonsson on 4/30/20.
//

#include <Client.h>
#include "IInstrumentsMetaApi.h"
#include "Exceptions.h"
#include "IBorsdata.h"
#include <boost/foreach.hpp>

class InstrumentsApi : IInstrumentsMetaApi, IBorsdata {
public:

    /// <summary>
    /// Returns all Branches Returns all Branches
    /// </summary>
    /// <param name="authKey">API Authentication Key</param>
    /// <returns>BranchesRespV1</returns>
    BranchesRespV1 Branchesv1 (string authKey) override
    {
        // verify the required parameter 'authKey' is set
        if (authKey.empty()) throw ConnectionExceptions(400, "Missing required parameter 'authKey' when calling Branchesv1");

        string url = getBaseUrl();
        url += "/v1/branches";
        addToken(url);
        ptree respData;
        Client::sendRequest(respData, url);
        auto obj = respData.get_child("branches");
        BOOST_ASSERT(!obj.empty());

        BranchesRespV1 resultResp;
        BOOST_FOREACH(boost::property_tree::ptree::value_type &val, obj)
        {
            BranchV1 result;
            result.id = val.second.get<long>("id");
            result.sectorId = val.second.get<long>("sectorId");
            result.name = val.second.get<string>("name");
            resultResp.branches.emplace_back(result);
        }
        return resultResp;
    }

    /// <summary>
    /// Returns all Countries Returns all Countries
    /// </summary>
    /// <param name="authKey">API Authentication Key</param>
    /// <returns>CountriesRespV1</returns>
    CountriesRespV1 Countriesv1 (string authKey) override
    {
        // verify the required parameter 'authKey' is set
        if (authKey.empty()) throw ConnectionExceptions(400, "Missing required parameter 'authKey' when calling Countriesv1");

        string url = getBaseUrl();
        url += "/v1/countries";
        addToken(url);
        ptree respData;
        Client::sendRequest(respData, url);
        auto obj = respData.get_child("countries");
        BOOST_ASSERT(!obj.empty());

        CountriesRespV1 resultResp;
        BOOST_FOREACH(boost::property_tree::ptree::value_type &val, obj)
        {
            CountryV1 result;
            result.id = val.second.get<long>("id");
            result.name = val.second.get<string>("name");
            resultResp.countries.emplace_back(result);
        }
        return resultResp;
    }

    /// <summary>
    /// Returns all Markets Returns all Markets
    /// </summary>
    /// <param name="authKey">API Authentication Key</param>
    /// <returns>MarketsRespV1</returns>
    MarketsRespV1 Marketsv1 (string authKey) override
    {
        // verify the required parameter 'authKey' is set
        if (authKey.empty()) throw ConnectionExceptions(400, "Missing required parameter 'authKey' when calling Marketsv1");

        string url = getBaseUrl();
        url += "/v1/markets";
        addToken(url);
        ptree respData;
        Client::sendRequest(respData, url);
        auto obj = respData.get_child("markets");
        BOOST_ASSERT(!obj.empty());

        MarketsRespV1 resultResp;
        BOOST_FOREACH(boost::property_tree::ptree::value_type &val, obj)
        {
            MarketV1 result;
            result.id = val.second.get<long>("id");
            result.name = val.second.get<string>("name");
            result.countryId = val.second.get<long>("countryId");
            result.exchangeName = val.second.get<string>("exchangeName");
            result.isIndex = val.second.get<bool>("isIndex");
            resultResp.markets.emplace_back(result);
        }
        return resultResp;
    }

    /// <summary>
    /// Returns all Sectors Returns all Sectors
    /// </summary>
    /// <param name="authKey">API Authentication Key</param>
    /// <returns>SectorsRespV1</returns>
    SectorsRespV1 Sectorsv1 (string authKey) override
    {
        // verify the required parameter 'authKey' is set
        if (authKey.empty()) throw ConnectionExceptions(400, "Missing required parameter 'authKey' when calling Sectorsv1");

        string url = getBaseUrl();
        url += "/v1/sectors";
        addToken(url);
        ptree respData;
        Client::sendRequest(respData, url);
        auto obj = respData.get_child("sectors");
        BOOST_ASSERT(!obj.empty());

        SectorsRespV1 resultResp;
        BOOST_FOREACH(boost::property_tree::ptree::value_type &val, obj)
                    {
                        SectorV1 result;
                        result.id = val.second.get<long>("id");
                        result.name = val.second.get<string>("name");
                        resultResp.sectors.emplace_back(result);
                    }
        return resultResp;
    }
};