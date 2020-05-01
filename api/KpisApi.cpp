//
// Created by mjonsson on 5/1/20.
//

#include <Client.h>
#include "KpisApi.h"
#include "Exceptions.h"
#include <boost/foreach.hpp>
#include "KpiHistoryV1.h"


/// <summary>
/// Returns Kpis History Returns Kpis History
/// </summary>
/// <param name="insid">Instrument Id</param>
/// <param name="kpiId">Kpi Id</param>
/// <param name="reporttype">Report Type </param>
/// <param name="pricetype">Price Type</param>
/// <returns>KpisHistoryRespV1</returns>
KpisHistoryRespV1 KpisApi::Histkpisv1 (int insid, int kpiId, string reporttype, string pricetype)
{
    // verify the required parameter 'insid' is set
    if (insid == 0) throw ConnectionExceptions(400, "Missing required parameter 'insid' when calling Histkpisv1");

    // verify the required parameter 'kpiId' is set
    if (kpiId == 0) throw ConnectionExceptions(400, "Missing required parameter 'kpiId' when calling Histkpisv1");

    // verify the required parameter 'reporttype' is set
    if (reporttype.empty())
        throw ConnectionExceptions(400, "Missing required parameter 'reporttype' when calling Histkpisv1");

    // verify the required parameter 'pricetype' is set
    if (pricetype.empty())
        throw ConnectionExceptions(400, "Missing required parameter 'pricetype' when calling Histkpisv1");

    string url = getBaseUrl();
    url += "/v1/instruments/{insid}/kpis/{kpiId}/{reporttype}/{pricetype}/history";
    replace(url, "{insid}", std::to_string(insid));
    replace(url, "{kpiId}", std::to_string(kpiId));
    replace(url, "{reporttype}", reporttype);
    replace(url, "{pricetype}", pricetype);
    addToken(url);
    ptree respData;
    Client::sendRequest(respData, url);
    BOOST_ASSERT(!respData.empty());

    KpisHistoryRespV1 resultResp;
    resultResp.jsonData = respData;
    BOOST_FOREACH(boost::property_tree::ptree::value_type &val, respData)
    {
        KpiHistoryV1 result;
        result.y = val.second.get<int>("y");
        result.p = val.second.get<int>("p");
        result.v = val.second.get<double>("v");
        resultResp.values.emplace_back(result);
    }
    resultResp.kpiId = respData.get<int>("kpiId");
    resultResp.reportTime = respData.get<string>("reportTime");
    resultResp.priceValue = respData.get<string>("priceValue");
    return resultResp;
}

/// <summary>
/// Returns Kpis Data for All Instruments Returns Kpis Data for All Instruments
/// </summary>
/// <param name="kpiId">Kpi Id</param>
/// <param name="calcGroup">Kpi Calculation Group. Mainly based on time.</param>
/// <param name="calc">Kpi Calculation</param>
/// <returns>KpisAllCompRespV1</returns>
KpisAllCompRespV1 KpisApi::Kpislistv1 (int kpiId, string calcGroup, string calc)
{
    // verify the required parameter 'kpiId' is set
    if (kpiId == 0) throw ConnectionExceptions(400, "Missing required parameter 'kpiId' when calling Kpislistv1");

    // verify the required parameter 'calcGroup' is set
    if (calcGroup.empty())
        throw ConnectionExceptions(400, "Missing required parameter 'calcGroup' when calling Kpislistv1");

    // verify the required parameter 'calc' is set
    if (calc.empty()) throw ConnectionExceptions(400, "Missing required parameter 'calc' when calling Kpislistv1");

    string url = getBaseUrl();
    url += "/v1/instruments/kpis/{kpiId}/{calcGroup}/{calc}";
    replace(url, "{calcGroup}", calcGroup);
    replace(url, "{kpiId}", std::to_string(kpiId));
    replace(url, "{calc}", calc);
    addToken(url);
    ptree respData;
    Client::sendRequest(respData, url);
    BOOST_ASSERT(!respData.empty());

    KpisAllCompRespV1 resultResp;
    resultResp.jsonData = respData;
    BOOST_FOREACH(boost::property_tree::ptree::value_type &val, respData)
    {
        KpiV1 result;
        result.i = val.second.get<long>("i");
        result.n = val.second.get<double>("n");
        result.s = val.second.get<string>("s");
        resultResp.values.emplace_back(result);
    }
    resultResp.kpiId = respData.get<int>("kpiId");
    resultResp.group = respData.get<string>("group");
    resultResp.calculation = respData.get<string>("calculation");
    return resultResp;
}

/// <summary>
/// Returns Kpis Calculation DateTime Returns Kpis Calculation DateTime
/// </summary>
/// <returns>KpisCalcUpdatedRespV1</returns>
KpisCalcUpdatedRespV1 KpisApi::Kpisupdatedv1 ()
{
    string url = getBaseUrl();
    url += "/v1/instruments/kpis/updated";
    addToken(url);
    ptree respData;
    Client::sendRequest(respData, url);
    BOOST_ASSERT(!respData.empty());

    KpisCalcUpdatedRespV1 resultResp;
    resultResp.jsonData = respData;
    resultResp.kpisCalcUpdated = respData.get<string>("kpisCalcUpdated");
}

/// <summary>
/// Returns Kpis Data for one Instrument Returns Kpis Data for one Instrument
/// </summary>
/// <param name="insid">Instrument Id</param>
/// <param name="kpiId">Kpi Id</param>
/// <param name="calcGroup">Kpi Calculation Group. Mainly based on time.</param>
/// <param name="calc">Kpi Calculation</param>
/// <returns>KpisRespV1</returns>
KpisRespV1 KpisApi::Kpisv1 (int insid, int kpiId, string calcGroup, string calc)
{
    // verify the required parameter 'insid' is set
    if (insid == 0) throw ConnectionExceptions(400, "Missing required parameter 'insid' when calling Kpisv1");

    // verify the required parameter 'kpiId' is set
    if (kpiId == 0) throw ConnectionExceptions(400, "Missing required parameter 'kpiId' when calling Kpisv1");

    // verify the required parameter 'calcGroup' is set
    if (calcGroup.empty())
        throw ConnectionExceptions(400, "Missing required parameter 'calcGroup' when calling Kpisv1");

    // verify the required parameter 'calc' is set
    if (calc.empty()) throw ConnectionExceptions(400, "Missing required parameter 'calc' when calling Kpisv1");

    string url = getBaseUrl();
    url += "/v1/instruments/{insid}/kpis/{kpiId}/{calcGroup}/{calc}";
    replace(url, "{calcGroup}", calcGroup);
    replace(url, "{insid}", std::to_string(insid));
    replace(url, "{kpiId}", std::to_string(kpiId));
    replace(url, "{calc}", calc);
    addToken(url);
    ptree respData;
    Client::sendRequest(respData, url);
    BOOST_ASSERT(!respData.empty());

    KpisRespV1 resultResp;
    resultResp.jsonData = respData;
    auto obj = respData.get_child("value");
    KpiV1 result;
    result.i = obj.get<long>("i");
    result.n = obj.get<double>("n");
    result.s = obj.get<string>("s");
    resultResp.value = result;

    resultResp.kpiId = respData.get<int>("kpiId");
    resultResp.group = respData.get<string>("group");
    resultResp.calculation = respData.get<string>("calculation");
    return resultResp;
}
