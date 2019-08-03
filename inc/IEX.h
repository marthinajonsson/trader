//
// Created by mjonsson on 1/11/19.
//

#ifndef TRADER_IEX_H
#define TRADER_IEX_H

#include <jsoncpp/json/json.h>
#include <curl/curl.h>
#include <locale> //std::locale, std::isdigit
#include <cassert>
#include <iostream>
#include <algorithm>
#include "Util.h"

const string IEX_ENDPOINT = "https://sandbox.iexapis.com/beta"; // "https://cloud.iexapis.com/stable"


namespace IEX {

    void sendHttpGetRequest(Json::Value &jsonData, string &url);
    void parseData(const Json::Value &IEXdata, vector <string> &argVec);
    void parseArgData(const Json::Value &IEXdata, vector <string> &argVec, string &&arg);

    bool isValidSymbol(const string &);

    namespace INDICATOR {
        /// \brief Require subscription plan
        namespace ADVANCED_STAT {
            static const string ADVANCED_STAT = "advanced-stats";
            namespace KEY {
                static const string PE = "pegRatio";
                static const string FORWARD_PE_RATIO = "forwardPERatio";
            }
        }

        namespace EARNINGS {
            static const string EARNINGS_ONE_YEAR = "earnings/1";
            namespace KEY {
                static const string ACTUAL_EPS = "actualEPS";
            }
        }

        namespace HISTORICAL_PRICES {
            static const string HIST_PRICE_ONE_MONTH = "chart/1m";
            static const string HIST_PRICE_THREE_MONTH = "chart/3m";
            static const string HIST_PRICE_SIX_MONTH = "chart/6m";
            static const string HIST_PRICE_ONE_YEAR = "chart/1y";
            static const string HIST_PRICE_TWO_YEAR = "chart/2y";
            static const string HIST_PRICE_FIVE_YEAR = "chart/5y";
        }

        namespace INSIDER {
            /// \brief Require subscription plan
            static const string INSIDER_SUMMARY = "insider-summary";

            static const string IPO_UPCOMING = "upcoming-ipos";
            static const string IPO_TODAY = "today_ipos";
        }

        namespace PRICE {
            static const string CURRENT_PRICE = "price";

            /// \brief Require subscription plan
            static const string INTRADAY_PRICES = "intraday-prices";

            static const string PREVIOUS_PRICE = "previous";
            namespace KEY_PREVIOUS_PRICE {
                static const string OPEN = "open";
                static const string CLOSED = "close";
                static const string CHANGE_PERCENT = "changePercent";
            }
        }

        namespace STATS {
            static const string STATS = "stats";
            namespace KEY {
                static const string PE_RATIO = "peRatio";
                static const string DAY_200_MOV_AVG = "day200MovingAvg";
                static const string DAY_50_MOV_AVG = "day50MovingAvg";
                static const string TRAILING_TWELVE_MONTHS_EARNING = "ttmEPS";
            }
        }
    }

    namespace ref {
        void parseLocalSymbol(const Json::Value &, vector<string> &);
        void parseDataList(const string&, const Json::Value &, vector<string> &);
        void parseDataListSorted(const string &type, const Json::Value &IEXdata, vector<string> &vec);
        vector<string> updateSymbolList();
        vector<string> updateRegionList();
        vector<string> getSymbolList();
        vector<string> getRegionList();
        vector<string> getSymbolListByRegion(string &&);
        Json::Value getISINList();
    }

    namespace stock {
        // EARNINGS, STATS, PRICE, PREVIOUS, HIST PRICE, INTRADAY PRICES
        // INSIDER SUMMARY, ADVANCED STATS
        Json::Value fetch(const string &symbol, const string &indicator, const string& filterKey = "");
        Json::Value company(const string &symbol);
    }

    namespace market {
        // IPOS
    }
}

#endif //TRADER_IEX_H
