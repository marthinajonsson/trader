//
// Created by mjonsson on 5/1/20.
//

#ifndef TRADER_REPORTV1_H
#define TRADER_REPORTV1_H


#include <Util.h>
#include <sstream>

class ReportV1 {
public:
    double revenues;
    double gross_Income;
    double operating_Income;
    double profit_Before_Tax;
    double profit_to_Equity_Holders;
    double earnings_Per_Share;
    double number_of_shares;
    double dividend;
    double intangible_assets;
    double tangible_assets;
    double financial_assets;
    double non_current_assets;
    double cash_and_equivalents;
    double current_assets;
    double total_Assets;
    double total_Equity;
    double non_current_liabilities;
    double current_liabilities;
    double total_Liabilities_And_Equity;
    double net_Debt;
    double cash_flow_from_operating_activities;
    double cash_flow_from_investing_activities;
    double cash_flow_from_financing_activities;
    double cash_flow_for_the_year;
    double free_Cash_Flow;
    double stock_Price_Average;
    double stock_Price_High;
    double stock_Price_Low;
    string currency;
    string report_Start_Date;
    string report_End_Date;

    string toString()  {
        std::stringstream ss;
        ss << "Revenues:" << revenues << "\n" <<
        "Gross_Income:" << gross_Income << "\n" <<
        "Operating_Income:" << operating_Income << "\n" <<
        "profit_Before_Tax:" << profit_Before_Tax << "\n" <<
        "Profit_to_Equity_Holders:" << profit_to_Equity_Holders << "\n" <<
        "Earnings_Per_Share:" << earnings_Per_Share << "\n" <<
        "Number_of_shares:" << number_of_shares << "\n" <<
        "Dividend:" << dividend << "\n" <<
        "Intangible_assets:" << intangible_assets << "\n" <<
        "Tangible_assets:" << tangible_assets << "\n" <<
        "Financial_assets:" << financial_assets << "\n" <<
        "Non_current_assets:" << non_current_assets << "\n" <<
        "Cash_and_equivalents:" << cash_and_equivalents << "\n" <<
        "Current_assets:" << current_assets << "\n" <<
        "Total_Assets:" << total_Assets << "\n" <<
        "Total_Equity:" << total_Equity << "\n" <<
        "Non_current_liabilities:" << non_current_liabilities << "\n" <<
        "Current_liabilities:" << current_liabilities << "\n" <<
        "Total_Liabilities_And_Equity:" << total_Liabilities_And_Equity << "\n" <<
        "Net_Debt:" << net_Debt << "\n" <<
        "Cash_flow_from_operating_activities:" << cash_flow_from_operating_activities << "\n" <<
        "Cash_flow_from_investing_activities:" << cash_flow_from_investing_activities << "\n" <<
        "Cash_flow_from_financing_activities:" << cash_flow_from_financing_activities << "\n" <<
        "Cash_flow_for_the_year:" << cash_flow_for_the_year << "\n" <<
        "Free_Cash_Flow:" << free_Cash_Flow << "\n" <<
        "Stock_Price_Average:" << stock_Price_Average << "\n" <<
        "Stock_Price_High:" << stock_Price_High << "\n" <<
        "Stock_Price_Low:" << stock_Price_Low << "\n" <<
        "Currency:" << currency << "\n" <<
        "Report_Start_Date:" << report_Start_Date << "\n" <<
        "Report_End_Date:" << report_End_Date << "\n";
        return ss.str();
    }
};



#endif //TRADER_REPORTV1_H
