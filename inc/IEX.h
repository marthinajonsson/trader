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

const string BASE_URL_ENDPOINT = "https://cloud.iexapis.com/stable";

namespace IEX
{
    template<typename T = string>
    void parseDataList(const string &type, const Json::Value &, vector<T> &);

    template<typename T = double>
    void parseArgData(const Json::Value &, vector <T> &, const string &);

    Json::Value fetch(const string &, const string &, const string& = "");
    void parseLocalSymbol(const Json::Value &, vector<string> &);
    vector<string> getSymbolList(const string &);
    bool isValidSymbol(const string &);

    template<typename T = string>
    void saveData(const string &, const string&, vector<T>&);
    void sendRequest(Json::Value &jsonData, string &url);
    void updateReferenceList(const string&);
    void addToken(string &url);

    namespace INDICATOR {
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
}

#endif //TRADER_IEX_H
