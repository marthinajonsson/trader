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
    typedef boost::property_tree::ptree ptree;

    const string BASE_URL_ENDPOINT = "https://apiservice.borsdata.se/";
    static const string ACCESS_KEY = "?authKey=";

    void sendRequest(ptree &, string &);
    void addToken(string &);


    namespace INSTRUMENTS {
        static const string instruments_v1 = "/v1/instruments/";
        static const string reports_v1 = "reports"; // /v1/instruments/{id}/reports
        static const string year_v1 = "year"; // /v1/instruments/{id}/reports/year
        static const string quarter_v1 = "year"; // /v1/instruments/{id}/reports/quarter
        static const string rolling12m_v1 = "r12"; // /v1/instruments/{id}/reports/r12
        static const string stockprices_v1 = "stockprices"; // /v1/instruments/{id}/stockprices
        static const string stocksplits_v1 = "StockSplits"; // /v1/instruments/StockSplits
        static const string stockpricesLast_v1 = "stockprices/last"; // /v1/instruments/stockprices/last
        static const string updated_v1 = "updated"; // /v1/instruments/updated
    }

    namespace MARKETS {
        static const string markets_v1 = "/v1/markets";
    }

    namespace SECTORS {
        static const string sectors_v1 = "/v1/sectors";
    }

    namespace COUNTRIES {
        static const string countries_v1 = "/v1/countries";
    }

    namespace BRANCHES {
        static const string branches_v1 = "/v1/branches";
    }
}

#endif //TRADER_BORSDATA_H
