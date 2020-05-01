//
// Created by mjonsson on 5/1/20.
//

#ifndef TRADER_IKPISAPI_H
#define TRADER_IKPISAPI_H


#include <Util.h>
#include <KpisHistoryRespV1.h>
#include <KpisAllCompRespV1.h>
#include <KpisCalcUpdatedRespV1.h>
#include <KpisRespV1.h>

class IKpisApi {
public:
    /// <summary>
    /// Returns Kpis History Returns Kpis History
    /// </summary>
    /// <param name="insid">Instrument Id</param>
    /// <param name="kpiId">Kpi Id</param>
    /// <param name="reporttype">Report Type </param>
    /// <param name="pricetype">Price Type</param>
    /// <param name="authKey">API Authentication Key</param>
    /// <returns>KpisHistoryRespV1</returns>
    virtual KpisHistoryRespV1 Histkpisv1 (int insid, int kpiId, string reporttype, string pricetype, string authKey) = 0;

    /// <summary>
    /// Returns Kpis Data for All Instruments Returns Kpis Data for All Instruments
    /// </summary>
    /// <param name="kpiId">Kpi Id</param>
    /// <param name="calcGroup">Kpi Calculation Group. Mainly based on time.</param>
    /// <param name="calc">Kpi Calculation</param>
    /// <param name="authKey">API Authentication Key</param>
    /// <returns>KpisAllCompRespV1</returns>
    virtual KpisAllCompRespV1 Kpislistv1 (int kpiId, string calcGroup, string calc, string authKey) = 0;

    /// <summary>
    /// Returns Kpis Calculation DateTime Returns Kpis Calculation DateTime
    /// </summary>
    /// <param name="authKey">API Authentication Key</param>
    /// <returns>KpisCalcUpdatedRespV1</returns>
    virtual KpisCalcUpdatedRespV1 Kpisupdatedv1 (string authKey) = 0;

    /// <summary>
    /// Returns Kpis Data for one Instrument Returns Kpis Data for one Instrument
    /// </summary>
    /// <param name="insid">Instrument Id</param>
    /// <param name="kpiId">Kpi Id</param>
    /// <param name="calcGroup">Kpi Calculation Group. Mainly based on time.</param>
    /// <param name="calc">Kpi Calculation</param>
    /// <param name="authKey">API Authentication Key</param>
    /// <returns>KpisRespV1</returns>
    virtual KpisRespV1 Kpisv1 (int insid, int kpiId, string calcGroup, string calc, string authKey) = 0;
};


#endif //TRADER_IKPISAPI_H
