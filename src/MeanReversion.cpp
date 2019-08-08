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

}
