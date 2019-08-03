//
// Created by mjonsson on 2/16/19.
//

#include "MeanReversion.h"
#include "IEX.h"

std::mutex single;
static MeanReversion *instance;

MeanReversion& MeanReversion::getInstance()
{
    std::lock_guard<std::mutex> lock(single);
    if(!instance) {
        instance = new MeanReversion();
    }
    return *instance;
}


/*
 * {
	"avgTotalVolume" : 25778006,
	"calculationPrice" : "tops",
	"change" : 2.1200000000000001,
	"changePercent" : 0.011390000000000001,
	"close" : 186.12,
	"closeTime" : 1552680000497,
	"companyName" : "Apple Inc.",
	"delayedPrice" : 187.88,
	"delayedPriceTime" : 1552919887568,
	"extendedChange" : 0,
	"extendedChangePercent" : 0,
	"extendedPrice" : 188.24000000000001,
	"extendedPriceTime" : 1552920788987,
	"high" : 188.38999999999999,
	"iexAskPrice" : 188.24000000000001,
	"iexAskSize" : 100,
	"iexBidPrice" : 187.81999999999999,
	"iexBidSize" : 100,
	"iexLastUpdated" : 1552920788987,
	"iexMarketPercent" : 0.02034,
	"iexRealtimePrice" : 188.24000000000001,
	"iexRealtimeSize" : 100,
	"iexVolume" : 186614,
	"latestPrice" : 188.24000000000001,
	"latestSource" : "IEX real time price",
	"latestTime" : "10:53:08 AM",
	"latestUpdate" : 1552920788987,
	"latestVolume" : 9174730,
	"low" : 185.78999999999999,
	"marketCap" : 887604307200,
	"open" : 185.90000000000001,
	"openTime" : 1552915800947,
	"peRatio" : 15.859999999999999,
	"previousClose" : 186.12,
	"primaryExchange" : "Nasdaq Global Select",
	"sector" : "Technology",
	"symbol" : "AAPL",
	"week52High" : 233.47,
	"week52Low" : 142,
	"ytdChange" : 0.19501687644479501
}
 All HTTP request endpoints support a filter parameter to return a subset of data. Pass a comma-delimited list of field names to filter. Field names are case-sensitive and are found in the Reference section of each endpoint.

Example: ?filter=symbol,volume,lastSalePrice will return only the three fields specified.
 */
void MeanReversion::run() {

    auto data = IEX::stock::fetch("AAPL", IEX::INDICATOR::PRICE::PREVIOUS_PRICE,
            IEX::INDICATOR::PRICE::KEY_PREVIOUS_PRICE::CLOSED);
    string prevClose = data.asString();

}
