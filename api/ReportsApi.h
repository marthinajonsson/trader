//
// Created by mjonsson on 5/1/20.
//

#ifndef TRADER_REPORTSAPI_H
#define TRADER_REPORTSAPI_H


#include <Util.h>
#include "IReportsApi.h"
#include "IBorsdata.h"

class ReportsApi : IReportsApi, IBorsdata {
private:
    bool replace(string &str, const string &from, const string &to) {
        size_t start_pos = str.find(from);
        if (start_pos == string::npos)
            return false;
        str.replace(start_pos, from.length(), to);
        return true;
    }

public:
    /// <summary>
    /// Returns Reports for Instrument. Max 10 reports. All Reports Type included (year, r12, quarter). Returns Reports for Instrument
    /// </summary>
    /// <param name="id">Instrument Id</param>
    /// <param name="version">The requested API version</param>
    /// <returns>ReportsCompoundRespV1</returns>
    ReportsCompoundRespV1 Reportscompoundv1 (int id, string version) override;

    /// <summary>
    /// Returns Reports for Instrument. Max 10 reports. Report Type (year, r12, quarter). Returns Reports for Instrument
    /// </summary>
    /// <param name="id">Instrument Id</param>
    /// <param name="reporttype">Report Type (year, r12, quarter)</param>
    /// <returns>ReportsRespV1</returns>
    ReportsRespV1 Reportsv1 (int id, string reporttype) override;
};
#endif //TRADER_REPORTSAPI_H
