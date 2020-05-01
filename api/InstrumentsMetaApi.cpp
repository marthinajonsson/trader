//
// Created by mjonsson on 4/30/20.
//

#include <Client.h>
#include "InstrumentsMetaApi.h"
#include <boost/foreach.hpp>

/// <summary>
/// Returns all Branches Returns all Branches
/// </summary>
/// <returns>BranchesRespV1</returns>
BranchesRespV1 InstrumentsMetaApi::Branchesv1 ()
{
    string url = getBaseUrl();
    url += "/v1/branches";
    addToken(url);
    ptree respData;
    Client::sendRequest(respData, url);
    auto obj = respData.get_child("branches");
    BOOST_ASSERT(!obj.empty());

    BranchesRespV1 resultResp;
    resultResp.jsonData = respData;
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
/// <returns>CountriesRespV1</returns>
CountriesRespV1 InstrumentsMetaApi::Countriesv1 ()
{
    string url = getBaseUrl();
    url += "/v1/countries";
    addToken(url);
    ptree respData;
    Client::sendRequest(respData, url);
    auto obj = respData.get_child("countries");
    BOOST_ASSERT(!obj.empty());

    CountriesRespV1 resultResp;
    resultResp.jsonData = respData;
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
/// <returns>MarketsRespV1</returns>
MarketsRespV1 InstrumentsMetaApi::Marketsv1 ()
{
    string url = getBaseUrl();
    url += "/v1/markets";
    addToken(url);
    ptree respData;
    Client::sendRequest(respData, url);
    auto obj = respData.get_child("markets");
    BOOST_ASSERT(!obj.empty());

    MarketsRespV1 resultResp;
    resultResp.jsonData = respData;
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
/// <returns>SectorsRespV1</returns>
SectorsRespV1 InstrumentsMetaApi::Sectorsv1 ()
{
    string url = getBaseUrl();
    url += "/v1/sectors";
    addToken(url);
    ptree respData;
    Client::sendRequest(respData, url);
    auto obj = respData.get_child("sectors");
    BOOST_ASSERT(!obj.empty());

    SectorsRespV1 resultResp;
    resultResp.jsonData = respData;
    BOOST_FOREACH(boost::property_tree::ptree::value_type &val, obj)
    {
        SectorV1 result;
        result.id = val.second.get<long>("id");
        result.name = val.second.get<string>("name");
        resultResp.sectors.emplace_back(result);
    }
    return resultResp;
}