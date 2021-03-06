//
// Created by mjonsson on 5/1/20.
//

#ifndef TRADER_IREPORTSAPI_H
#define TRADER_IREPORTSAPI_H


#include <ReportsCompoundRespV1.h>
#include <ReportsRespV1.h>

class IReportsApi {
protected:

    /// <summary>
    /// Returns Reports for Instrument. Max 10 reports. All Reports Type included (year, r12, quarter). Returns Reports for Instrument
    /// </summary>
    /// <param name="id">Instrument Id</param>
    /// <param name="version">The requested API version</param>
    /// <returns>ReportsCompoundRespV1</returns>
    virtual ReportsCompoundRespV1 Reportscompoundv1 (int id, string version) = 0;
    /// <summary>
    /// Returns Reports for Instrument. Max 10 reports. Report Type (year, r12, quarter). Returns Reports for Instrument
    /// </summary>
    /// <param name="id">Instrument Id</param>
    /// <param name="reporttype">Report Type (year, r12, quarter)</param>
    /// <returns>ReportsRespV1</returns>
    virtual ReportsRespV1 Reportsv1 (int id, string reporttype) = 0;
};


#endif //TRADER_IREPORTSAPI_H
