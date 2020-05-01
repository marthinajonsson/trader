//
// Created by mjonsson on 5/1/20.
//

#ifndef TRADER_KPISAPI_H
#define TRADER_KPISAPI_H

#include "IKpisApi.h"
#include "Exceptions.h"
#include "IBorsdata.h"
#include <boost/foreach.hpp>
#include "KpiHistoryV1.h"

/// <summary>
/// Represents a collection of functions to interact with the API endpoints
/// </summary>
class KpisApi : IKpisApi, IBorsdata {
protected:
    static bool replace(string &str, const string &from, const string &to) {
        size_t start_pos = str.find(from);
        if (start_pos == string::npos)
            return false;
        str.replace(start_pos, from.length(), to);
        return true;
    }

public:

    /// <summary>
    /// Returns Kpis History Returns Kpis History
    /// </summary>
    /// <param name="insid">Instrument Id</param>
    /// <param name="kpiId">Kpi Id</param>
    /// <param name="reporttype">Report Type </param>
    /// <param name="pricetype">Price Type</param>
    /// <returns>KpisHistoryRespV1</returns>
    KpisHistoryRespV1 Histkpisv1 (int insid, int kpiId, string reporttype, string pricetype) override;

    /// <summary>
    /// Returns Kpis Data for All Instruments Returns Kpis Data for All Instruments
    /// </summary>
    /// <param name="kpiId">Kpi Id</param>
    /// <param name="calcGroup">Kpi Calculation Group. Mainly based on time.</param>
    /// <param name="calc">Kpi Calculation</param>
    /// <returns>KpisAllCompRespV1</returns>
    KpisAllCompRespV1 Kpislistv1 (int kpiId, string calcGroup, string calc) override;


    /// <summary>
    /// Returns Kpis Calculation DateTime Returns Kpis Calculation DateTime
    /// </summary>
    /// <returns>KpisCalcUpdatedRespV1</returns>
    KpisCalcUpdatedRespV1 Kpisupdatedv1 () override;

    /// <summary>
    /// Returns Kpis Data for one Instrument Returns Kpis Data for one Instrument
    /// </summary>
    /// <param name="insid">Instrument Id</param>
    /// <param name="kpiId">Kpi Id</param>
    /// <param name="calcGroup">Kpi Calculation Group. Mainly based on time.</param>
    /// <param name="calc">Kpi Calculation</param>
    /// <returns>KpisRespV1</returns>
    KpisRespV1 Kpisv1 (int insid, int kpiId, string calcGroup, string calc) override;
};
#endif //TRADER_KPISAPI_H
