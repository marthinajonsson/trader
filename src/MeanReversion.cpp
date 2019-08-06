//
// Created by mjonsson on 2/16/19.
//

#include "MeanReversion.h"
#include "UniBit.h"

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

void MeanReversion::run()
{
    string key = UNIBIT::INDICATOR::KEY_REQUEST_DATA_POINT;
    key = key.append("200");
    key = key.append(UNIBIT::INDICATOR::KEY_REQUEST_SERIES_TYPE).append("close");
    key = key.append(UNIBIT::INDICATOR::KEY_REQUEST_INTERVAL).append("daily");
    key = key.append(UNIBIT::INDICATOR::KEY_REQUEST_RANGE).append("6m");
    UNIBIT::fetch("MSFT", UNIBIT::INDICATOR::BASE_REQUEST, key);
}
