//
// Created by mjonsson on 8/5/19.
//

#ifndef TRADER_UNIBIT_H
#define TRADER_UNIBIT_H

#include <boost/property_tree/json_parser.hpp>
#include "json_streamer.h"
#include "Util.h"

namespace UNIBIT
{
    typedef boost::property_tree::ptree ptree;
    const string BASE_URL_ENDPOINT = "https://api.unibit.ai/api";
    void parseArgData(const ptree &, vector<string> &, const string &, const string & ...);
    void saveData(const string &, const string&, vector<string>&);

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
