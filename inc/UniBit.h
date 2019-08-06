//
// Created by mjonsson on 8/5/19.
//

#ifndef TRADER_UNIBIT_H
#define TRADER_UNIBIT_H

#include <jsoncpp/json/json.h>
#include "Util.h"

namespace UNIBIT
{
    const string BASE_URL_ENDPOINT = "https://api.unibit.ai/api";

    void parseArgData(const Json::Value &response, vector<string> &argVec, const string &arg);
    void saveData(const string &name, const string& type, vector<string>& data);
    Json::Value fetch(const string &, const string &, const string& = "");
    void sendRequest(Json::Value &jsonData, string &url);
    void updateReferenceList(const string& exchange);
    void addToken(string &url);

    static const string TICKER = "ticker=";
    static const string ACCESS_KEY = "&AccessKey=";

    namespace INDICATOR {
        static const string BASE_REQUEST = "/technicalindicators?";
        static const string KEY_REQUEST_DATA_POINT ="&data_point=";
        static const string KEY_REQUEST_SERIES_TYPE ="&series_type=";
        static const string KEY_REQUEST_INTERVAL ="&interval=";
        static const string KEY_REQUEST_RANGE = "&range=";

        namespace SMA {
            static const string KEY_REQUEST_FUNC = "&function=SMA";

            namespace KEY_RESPONSE {
                static const string BASE = "Technical Indicator: SMA";
                static const string DATE = "datetime";
                static const string CALC = "SMA";
            }
        }
        namespace DEMA {
            static const string KEY_REQUEST_FUNC = "&function=DEMA";

            namespace KEY_RESPONSE {
                static const string BASE = "Technical Indicator: DEMA";
                static const string DATE = "datetime";
                static const string CALC = "DEMA";
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
