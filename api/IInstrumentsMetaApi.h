//
// Created by mjonsson on 4/30/20.
//

#ifndef TRADER_IINSTRUMENTSMETAAPI_H
#define TRADER_IINSTRUMENTSMETAAPI_H

#include <MarketsRespV1.h>
#include <CountriesRespV1.h>
#include <BranchesRespV1.h>
#include <SectorsRespV1.h>

class IInstrumentsMetaApi {
protected:
    /// <summary>
    /// Returns all Branches Returns all Branches
    /// </summary>
    /// <returns>BranchesRespV1</returns>
    virtual BranchesRespV1 Branchesv1 () = 0;
    /// <summary>
    /// Returns all Countries Returns all Countries
    /// </summary>
    /// <returns>CountriesRespV1</returns>
    virtual CountriesRespV1 Countriesv1 () = 0;
    /// <summary>
    /// Returns all Markets Returns all Markets
    /// </summary>
    /// <returns>MarketsRespV1</returns>
    virtual MarketsRespV1 Marketsv1 () = 0;
    /// <summary>
    /// Returns all Sectors Returns all Sectors
    /// </summary>
    /// <returns>SectorsRespV1</returns>
    virtual SectorsRespV1 Sectorsv1 () = 0;
};

#endif //TRADER_IINSTRUMENTSMETAAPI_H
