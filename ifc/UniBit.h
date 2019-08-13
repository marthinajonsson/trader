//
// Created by mjonsson on 8/5/19.
//

#ifndef TRADER_UNIBIT_H
#define TRADER_UNIBIT_H

#include <boost/foreach.hpp>
#include <boost/property_tree/json_parser.hpp>
#include "json_streamer.h"
#include <iostream>
#include "Util.h"

namespace UNIBIT
{
    typedef boost::property_tree::ptree ptree;
    const string BASE_URL_ENDPOINT = "https://api.unibit.ai/api";

    template<typename T>
    std::pair<T,T> parseData(boost::property_tree::ptree pt, vector<std::pair<T,T>> result, T v) {
        return std::make_pair(v, pt.get<T>(v));
    }

    template<typename T, typename... Args>
    std::pair<T,T> parseData(boost::property_tree::ptree pt, vector<std::pair<T,T>> &result , T first, Args... args) {
        result.emplace_back(std::make_pair(first, pt.get<T>(first)));
        result.emplace_back(parseData(pt, result, args...));
        return {"",""};
    }

    template<typename ...T>
    vector<std::pair<string, string>> parseArgData(const ptree &response, T&&... args)
    {
        BOOST_ASSERT(!response.empty());
        ptree path;
        ptree child;
        try
        {
            child = response.get_child("", path);
        }
        catch(const boost::property_tree::ptree_bad_path &e)
        {
            std::cout << e.what() << std::endl;
            child = response;
        }

        vector<std::pair<string, string>> result;
        BOOST_FOREACH(boost::property_tree::ptree::value_type &arr, child) {
            std::pair<string, string> temp = parseData(arr.second, result, args...);
        }
        return result;
    }

    void saveData(const string &name, const string& type, vector<std::pair<string, string>>& data);
    ptree fetch(const string &, const string& = "");
    void sendRequest(ptree &, string &);
    void updateReferenceList(const string&);
    void addToken(string &);

    static const string TICKER = "ticker=";
    static const string ACCESS_KEY = "&AccessKey=";

    namespace INDICATOR {
        static const string BASE_REQUEST = "/technicalindicators?";
        static const string DATA_POINT_KEY ="&data_point=";
        static const string DATA_POINT_VALUE_14 = "14";
        static const string DATA_POINT_VALUE_20 = "20";
        static const string DATA_POINT_VALUE_50 = "50";
        static const string DATA_POINT_VALUE_200 = "200";
        static const string SERIES_TYPE_KEY ="&series_type=";

        static const string INTERVAL_KEY ="&interval=";
        static const string INTERVAL_DAILY_VALUE ="daily";
        static const string INTERVAL_MONTH_VALUE ="monthly";
        static const string INTERVAL_WEEK_VALUE ="weekly";

        static const string RANGE_KEY = "&range=";

        namespace SMA {
            static const string KEY_REQUEST_FUNC = "&function=SMA";

            namespace KEY_RESPONSE {
                static const string BASE = "Technical Indicator: SMA";
                static const string DATE = "datetime";
                static const string CALC = "SMA";
            }
        }
        namespace ADX {
            static const string KEY_REQUEST_FUNC = "&function=ADX";

            namespace KEY_RESPONSE {
                static const string BASE = "Technical Indicator: ADX";
                static const string DATE = "date";
                static const string CALC = "price";
            }
        }
    }

    namespace REALTIME_PRICE {
        static const string BASE_REQUEST = "/realtimestock";
        static const string KEY_REQUEST_SIZE = "&size=";
        namespace KEY_RESPONSE {
            static const string BASE = "Realtime Stock price";
            static const string DATE = "date";
            static const string VOLUME = "volume";
            static const string PRICE = "price";
        }

        namespace HISTORICAL_PRICE {
            static const string BASE_REQUEST = "/historicalstockprice/";
            static const string KEY_REQUEST_RANGE = "&range=";
            static const string KEY_REQUEST_INTERVAL = "&interval=";
            namespace KEY_RESPONSE {
                static const string BASE = "Stock Price";
                static const string DATE = "date";
                static const string OPEN = "open";
                static const string CLOSE = "close";
                static const string ADJ_CLOSE = "adj_close";
                static const string VOLUME = "volume";
                static const string HIGH = "high";
                static const string LOW = "low";
            }
        }
    }

    namespace SYMBOLS {
        static const string BASE_REQUEST = "/companylist?";
        static const string KEY_REQUEST_EXCHANGE = "exchange=";
        namespace KEY_RESPONSE {
            static const string NAME = "companyName";
            static const string EXCHANGE_NAME = "exchange";
            static const string CURRENCY = "currency";
            static const string TICKER = "ticker";
        }
    }
};
#endif //TRADER_UNIBIT_H
