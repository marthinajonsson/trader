//
// Created by mjonsson on 4/30/20.
//

#include <Client.h>
#include "IInstrumentsMetaApi.h"
#include "Exceptions.h"
#include "IBorsdata.h"

class InstrumentsApi : IInstrumentsMetaApi, IBorsdata {
public:

    /// <summary>
    /// Returns all Branches Returns all Branches
    /// </summary>
    /// <param name="authKey">API Authentication Key</param>
    /// <returns>BranchesRespV1</returns>
    BranchesRespV1 Branchesv1 (string authKey) override
    {
        // verify the required parameter 'authKey' is set
        if (authKey.empty()) throw ConnectionExceptions(400, "Missing required parameter 'authKey' when calling Branchesv1");

        string url = getBaseUrl();
        url += "/v1/branches";
        addToken(url);
        //Client::getInstance().sendRequest(respData, url);
    }

    /// <summary>
    /// Returns all Countries Returns all Countries
    /// </summary>
    /// <param name="authKey">API Authentication Key</param>
    /// <returns>CountriesRespV1</returns>
    CountriesRespV1 Countriesv1 (string authKey) override
    {
        // verify the required parameter 'authKey' is set
        if (authKey.empty()) throw ConnectionExceptions(400, "Missing required parameter 'authKey' when calling Countriesv1");

        string url = getBaseUrl();
        url += "/v1/countries";
        addToken(url);
        //Client::getInstance().sendRequest(respData, url);
    }

    /// <summary>
    /// Returns all Markets Returns all Markets
    /// </summary>
    /// <param name="authKey">API Authentication Key</param>
    /// <returns>MarketsRespV1</returns>
    MarketsRespV1 Marketsv1 (string authKey) override
    {
        // verify the required parameter 'authKey' is set
        if (authKey.empty()) throw ConnectionExceptions(400, "Missing required parameter 'authKey' when calling Marketsv1");

        string url = getBaseUrl();
        url += "/v1/markets";
        addToken(url);
        //Client::getInstance().sendRequest(respData, url);
    }

    /// <summary>
    /// Returns all Sectors Returns all Sectors
    /// </summary>
    /// <param name="authKey">API Authentication Key</param>
    /// <returns>SectorsRespV1</returns>
    SectorsRespV1 Sectorsv1 (string authKey) override
    {
        // verify the required parameter 'authKey' is set
        if (authKey.empty()) throw ConnectionExceptions(400, "Missing required parameter 'authKey' when calling Sectorsv1");

        string url = getBaseUrl();
        url += "/v1/sectors";
        addToken(url);
        //Client::getInstance().sendRequest(respData, url);
    }
};