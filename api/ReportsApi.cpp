//
// Created by mjonsson on 5/1/20.
//

#include <Client.h>
#include "Exceptions.h"
#include "IBorsdata.h"
#include "IReportsApi.h"
#include <boost/foreach.hpp>

class ReportsApi : IReportsApi, IBorsdata {
private:
    bool replace(string& str, const string& from, const string& to) {
        size_t start_pos = str.find(from);
        if(start_pos == string::npos)
            return false;
        str.replace(start_pos, from.length(), to);
        return true;
    }

public:
    /// <summary>
    /// Returns Reports for Instrument. Max 10 reports. All Reports Type included (year, r12, quarter). Returns Reports for Instrument
    /// </summary>
    /// <param name="id">Instrument Id</param>
    /// <param name="authKey">API Authentication Key</param>
    /// <param name="version">The requested API version</param>
    /// <returns>ReportsCompoundRespV1</returns>
    ReportsCompoundRespV1 Reportscompoundv1 (int id, string authKey, string version) override
    {
        // verify the required parameter 'id' is set
        if (id == 0) throw ConnectionExceptions(400, "Missing required parameter 'id' when calling Reportscompoundv1");

        // verify the required parameter 'authKey' is set
        if (authKey.empty())
            throw ConnectionExceptions(400, "Missing required parameter 'authKey' when calling Reportscompoundv1");

        // verify the required parameter 'version' is set
        if (version.empty())
            throw ConnectionExceptions(400, "Missing required parameter 'version' when calling Reportscompoundv1");

        string url = getBaseUrl();
        url += "/v1/instruments/{id}/reports";
        replace(url, "{id}", std::to_string(id));
        addToken(url);
        ptree respData;
        Client::sendRequest(respData, url);

        ReportsCompoundRespV1 resultResp;
        resultResp.instrument = respData.get<int>("instrument");
        auto obj = respData.get_child("reportsYear");
        BOOST_ASSERT(!obj.empty());
        BOOST_FOREACH(boost::property_tree::ptree::value_type &val, obj)
        {
            ReportV1 result;
            result.cash_and_equivalents = val.second.get<double>("cash_and_equivalents");
            result.cash_flow_for_the_year = val.second.get<double>("cash_flow_for_the_year");
            result.cash_flow_from_financing_activities = val.second.get<double>("cash_flow_from_financing_activities");
            result.cash_flow_from_investing_activities = val.second.get<double>("cash_flow_from_investing_activities");
            result.cash_flow_from_operating_activities = val.second.get<double>("cash_flow_from_operating_activities");
            result.currency = val.second.get<string>("currency");
            result.current_assets = val.second.get<double>("current_assets");
            result.current_liabilities = val.second.get<double>("current_liabilities");
            result.dividend = val.second.get<double>("dividend");
            result.earnings_Per_Share = val.second.get<double>("earnings_Per_Share");
            result.financial_assets = val.second.get<double>("financial_assets");
            result.free_Cash_Flow = val.second.get<double>("free_Cash_Flow");
            result.gross_Income = val.second.get<double>("gross_Income");
            result.intangible_assets = val.second.get<double>("intangible_assets");
            result.net_Debt = val.second.get<double>("net_Debt");
            result.non_current_assets = val.second.get<double>("non_current_assets");
            result.non_current_liabilities = val.second.get<double>("non_current_liabilities");
            result.number_of_shares = val.second.get<double>("number_of_shares");
            result.operating_Income = val.second.get<double>("operating_Income");
            result.profit_Before_Tax = val.second.get<double>("profit_Before_Tax");
            result.profit_to_Equity_Holders = val.second.get<double>("profit_to_Equity_Holders");
            result.report_End_Date = val.second.get<string>("report_End_Date");
            result.report_Start_Date = val.second.get<string>("report_Start_Date");
            result.revenues = val.second.get<double>("revenues");
            result.stock_Price_Average = val.second.get<double>("stock_Price_Average");
            result.stock_Price_High = val.second.get<double>("stock_Price_High");
            result.stock_Price_Low = val.second.get<double>("stock_Price_Low");
            result.tangible_assets = val.second.get<double>("tangible_assets");
            result.total_Assets = val.second.get<double>("total_Assets");
            result.total_Equity = val.second.get<double>("total_Equity");
            result.total_Liabilities_And_Equity = val.second.get<double>("total_Liabilities_And_Equity");
            resultResp.reportsYear.emplace_back(result);
        }

        obj = respData.get_child("reportsQuarter");
        BOOST_ASSERT(!obj.empty());
        BOOST_FOREACH(boost::property_tree::ptree::value_type &val, obj)
        {
            ReportV1 result;
            result.cash_and_equivalents = val.second.get<double>("cash_and_equivalents");
            result.cash_flow_for_the_year = val.second.get<double>("cash_flow_for_the_year");
            result.cash_flow_from_financing_activities = val.second.get<double>("cash_flow_from_financing_activities");
            result.cash_flow_from_investing_activities = val.second.get<double>("cash_flow_from_investing_activities");
            result.cash_flow_from_operating_activities = val.second.get<double>("cash_flow_from_operating_activities");
            result.currency = val.second.get<string>("currency");
            result.current_assets = val.second.get<double>("current_assets");
            result.current_liabilities = val.second.get<double>("current_liabilities");
            result.dividend = val.second.get<double>("dividend");
            result.earnings_Per_Share = val.second.get<double>("earnings_Per_Share");
            result.financial_assets = val.second.get<double>("financial_assets");
            result.free_Cash_Flow = val.second.get<double>("free_Cash_Flow");
            result.gross_Income = val.second.get<double>("gross_Income");
            result.intangible_assets = val.second.get<double>("intangible_assets");
            result.net_Debt = val.second.get<double>("net_Debt");
            result.non_current_assets = val.second.get<double>("non_current_assets");
            result.non_current_liabilities = val.second.get<double>("non_current_liabilities");
            result.number_of_shares = val.second.get<double>("number_of_shares");
            result.operating_Income = val.second.get<double>("operating_Income");
            result.profit_Before_Tax = val.second.get<double>("profit_Before_Tax");
            result.profit_to_Equity_Holders = val.second.get<double>("profit_to_Equity_Holders");
            result.report_End_Date = val.second.get<string>("report_End_Date");
            result.report_Start_Date = val.second.get<string>("report_Start_Date");
            result.revenues = val.second.get<double>("revenues");
            result.stock_Price_Average = val.second.get<double>("stock_Price_Average");
            result.stock_Price_High = val.second.get<double>("stock_Price_High");
            result.stock_Price_Low = val.second.get<double>("stock_Price_Low");
            result.tangible_assets = val.second.get<double>("tangible_assets");
            result.total_Assets = val.second.get<double>("total_Assets");
            result.total_Equity = val.second.get<double>("total_Equity");
            result.total_Liabilities_And_Equity = val.second.get<double>("total_Liabilities_And_Equity");
            resultResp.reportsQuarter.emplace_back(result);
        }
        obj = respData.get_child("reportsR12");
        BOOST_ASSERT(!obj.empty());
        BOOST_FOREACH(boost::property_tree::ptree::value_type &val, obj)
        {
            ReportV1 result;
            result.cash_and_equivalents = val.second.get<double>("cash_and_equivalents");
            result.cash_flow_for_the_year = val.second.get<double>("cash_flow_for_the_year");
            result.cash_flow_from_financing_activities = val.second.get<double>("cash_flow_from_financing_activities");
            result.cash_flow_from_investing_activities = val.second.get<double>("cash_flow_from_investing_activities");
            result.cash_flow_from_operating_activities = val.second.get<double>("cash_flow_from_operating_activities");
            result.currency = val.second.get<string>("currency");
            result.current_assets = val.second.get<double>("current_assets");
            result.current_liabilities = val.second.get<double>("current_liabilities");
            result.dividend = val.second.get<double>("dividend");
            result.earnings_Per_Share = val.second.get<double>("earnings_Per_Share");
            result.financial_assets = val.second.get<double>("financial_assets");
            result.free_Cash_Flow = val.second.get<double>("free_Cash_Flow");
            result.gross_Income = val.second.get<double>("gross_Income");
            result.intangible_assets = val.second.get<double>("intangible_assets");
            result.net_Debt = val.second.get<double>("net_Debt");
            result.non_current_assets = val.second.get<double>("non_current_assets");
            result.non_current_liabilities = val.second.get<double>("non_current_liabilities");
            result.number_of_shares = val.second.get<double>("number_of_shares");
            result.operating_Income = val.second.get<double>("operating_Income");
            result.profit_Before_Tax = val.second.get<double>("profit_Before_Tax");
            result.profit_to_Equity_Holders = val.second.get<double>("profit_to_Equity_Holders");
            result.report_End_Date = val.second.get<string>("report_End_Date");
            result.report_Start_Date = val.second.get<string>("report_Start_Date");
            result.revenues = val.second.get<double>("revenues");
            result.stock_Price_Average = val.second.get<double>("stock_Price_Average");
            result.stock_Price_High = val.second.get<double>("stock_Price_High");
            result.stock_Price_Low = val.second.get<double>("stock_Price_Low");
            result.tangible_assets = val.second.get<double>("tangible_assets");
            result.total_Assets = val.second.get<double>("total_Assets");
            result.total_Equity = val.second.get<double>("total_Equity");
            result.total_Liabilities_And_Equity = val.second.get<double>("total_Liabilities_And_Equity");
            resultResp.reportsR12.emplace_back(result);
        }
        return resultResp;
    }


    /// <summary>
    /// Returns Reports for Instrument. Max 10 reports. Report Type (year, r12, quarter). Returns Reports for Instrument
    /// </summary>
    /// <param name="id">Instrument Id</param>
    /// <param name="reporttype">Report Type (year, r12, quarter)</param>
    /// <param name="authKey">API Authentication Key</param>
    /// <returns>ReportsRespV1</returns>
    ReportsRespV1 Reportsv1 (int id, string reporttype, string authKey) override
    {

        // verify the required parameter 'id' is set
        if (id == 0) throw ConnectionExceptions(400, "Missing required parameter 'id' when calling Reportsv1");

        // verify the required parameter 'reporttype' is set
        if (reporttype.empty())
            throw ConnectionExceptions(400, "Missing required parameter 'reporttype' when calling Reportsv1");

        // verify the required parameter 'authKey' is set
        if (authKey.empty()) throw ConnectionExceptions(400, "Missing required parameter 'authKey' when calling Reportsv1");

        string url = getBaseUrl();
        url += "/v1/instruments/{id}/reports/{reporttype}";
        replace(url, "{id}", std::to_string(id));
        replace(url, "{reporttype}", reporttype);
        addToken(url);
        ptree respData;
        Client::sendRequest(respData, url);

        ReportsRespV1 resultResp;
        resultResp.instrument = respData.get<long>("instrument");
        auto obj = respData.get_child("reports");
        BOOST_ASSERT(!obj.empty());
        BOOST_FOREACH(boost::property_tree::ptree::value_type &val, obj)
        {
            ReportV1 result;
            result.cash_and_equivalents = val.second.get<double>("cash_and_equivalents");
            result.cash_flow_for_the_year = val.second.get<double>("cash_flow_for_the_year");
            result.cash_flow_from_financing_activities = val.second.get<double>("cash_flow_from_financing_activities");
            result.cash_flow_from_investing_activities = val.second.get<double>("cash_flow_from_investing_activities");
            result.cash_flow_from_operating_activities = val.second.get<double>("cash_flow_from_operating_activities");
            result.currency = val.second.get<string>("currency");
            result.current_assets = val.second.get<double>("current_assets");
            result.current_liabilities = val.second.get<double>("current_liabilities");
            result.dividend = val.second.get<double>("dividend");
            result.earnings_Per_Share = val.second.get<double>("earnings_Per_Share");
            result.financial_assets = val.second.get<double>("financial_assets");
            result.free_Cash_Flow = val.second.get<double>("free_Cash_Flow");
            result.gross_Income = val.second.get<double>("gross_Income");
            result.intangible_assets = val.second.get<double>("intangible_assets");
            result.net_Debt = val.second.get<double>("net_Debt");
            result.non_current_assets = val.second.get<double>("non_current_assets");
            result.non_current_liabilities = val.second.get<double>("non_current_liabilities");
            result.number_of_shares = val.second.get<double>("number_of_shares");
            result.operating_Income = val.second.get<double>("operating_Income");
            result.profit_Before_Tax = val.second.get<double>("profit_Before_Tax");
            result.profit_to_Equity_Holders = val.second.get<double>("profit_to_Equity_Holders");
            result.report_End_Date = val.second.get<string>("report_End_Date");
            result.report_Start_Date = val.second.get<string>("report_Start_Date");
            result.revenues = val.second.get<double>("revenues");
            result.stock_Price_Average = val.second.get<double>("stock_Price_Average");
            result.stock_Price_High = val.second.get<double>("stock_Price_High");
            result.stock_Price_Low = val.second.get<double>("stock_Price_Low");
            result.tangible_assets = val.second.get<double>("tangible_assets");
            result.total_Assets = val.second.get<double>("total_Assets");
            result.total_Equity = val.second.get<double>("total_Equity");
            result.total_Liabilities_And_Equity = val.second.get<double>("total_Liabilities_And_Equity");
            resultResp.reports.emplace_back(result);
        }
        return resultResp;
    }
};