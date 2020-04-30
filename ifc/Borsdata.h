//
// Created by mjonsson on 4/19/20.
//

#ifndef TRADER_BORSDATA_H
#define TRADER_BORSDATA_H

#include <boost/property_tree/json_parser.hpp>
#include "json_streamer.h"
#include <iostream>
#include "Util.h"

namespace BORSDATA {

        namespace KPIS {

        }

        namespace REPORTS {
            static const string reports_v1 = "reports"; // /v1/instruments/{id}/reports
            static const string year_v1 = "year"; // /v1/instruments/{id}/reports/year
            static const string quarter_v1 = "year"; // /v1/instruments/{id}/reports/quarter
            static const string rolling12m_v1 = "r12"; // /v1/instruments/{id}/reports/r12

            /*
             * ReportV1{
                year	integer($int32)
                period	integer($int32)
                revenues	number($double)
                gross_Income	number($double)
                operating_Income	number($double)
                profit_Before_Tax	number($double)
                profit_To_Equity_Holders	number($double)
                earnings_Per_Share	number($double)
                number_Of_Shares	number($double)
                dividend	number($double)
                intangible_Assets	number($double)
                tangible_Assets	number($double)
                financial_Assets	number($double)
                non_Current_Assets	number($double)
                cash_And_Equivalents	number($double)
                current_Assets	number($double)
                total_Assets	number($double)
                total_Equity	number($double)
                non_Current_Liabilities	number($double)
                current_Liabilities	number($double)
                total_Liabilities_And_Equity	number($double)
                net_Debt	number($double)
                cash_Flow_From_Operating_Activities	number($double)
                cash_Flow_From_Investing_Activities	number($double)
                cash_Flow_From_Financing_Activities	number($double)
                cash_Flow_For_The_Year	number($double)
                free_Cash_Flow	number($double)
                stock_Price_Average	number($double)
                stock_Price_High	number($double)
                stock_Price_Low	number($double)
                report_Start_Date	string($date-time)
                report_End_Date	string($date-time)
                broken_Fiscal_Year	boolean
                }
             * */
        }

        namespace STOCKPRICES {
            static const string stockprices_v1 = "stockprices"; // /v1/instruments/{id}/stockprices
            static const string stockpricesLast_v1 = "stockprices/last"; // /v1/instruments/stockprices/last
            static const string stockpricesDate_v1 = "stockprices/date"; // /v1/instruments/stockprices/date

            /*StockPriceV1{
                d	string
                Date
                h	number($double)
                Highest Price
                l	number($double)
                Lowest Price
                c	number($double)
                Closing Price
                o	number($double)
                Opening Price
                v	integer($int64)
                Total Volume
                }*/
        }

        static const string stocksplits_v1 = "StockSplits"; // /v1/instruments/StockSplits

}

#endif //TRADER_BORSDATA_H
