//
// Created by mjonsson on 5/1/20.
//

#ifndef TRADER_INSTRUMENTSMETAAPI_H
#define TRADER_INSTRUMENTSMETAAPI_H

#include "IInstrumentsMetaApi.h"
#include "IBorsdata.h"

class InstrumentsMetaApi : IInstrumentsMetaApi, IBorsdata {
public:

    /// <summary>
    /// Returns all Branches Returns all Branches
    /// </summary>
    /// <returns>BranchesRespV1</returns>
    BranchesRespV1 Branchesv1 () override;

    /// <summary>
    /// Returns all Countries Returns all Countries
    /// </summary>
    /// <returns>CountriesRespV1</returns>
    CountriesRespV1 Countriesv1 () override;

    /// <summary>
    /// Returns all Markets Returns all Markets
    /// </summary>
    /// <returns>MarketsRespV1</returns>
    MarketsRespV1 Marketsv1 () override;

    /// <summary>
    /// Returns all Sectors Returns all Sectors
    /// </summary>
    /// <returns>SectorsRespV1</returns>
    SectorsRespV1 Sectorsv1 () override;
};

#endif //TRADER_INSTRUMENTSMETAAPI_H
