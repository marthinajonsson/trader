//
// Created by mjonsson on 2/15/19.
//


#include <TaLib.h>

void TechnicalInvest::errorHandler(TA_RetCode &retCode) const {

    if (retCode == TA_SUCCESS) {
        return;
    }

    const static struct errors {
        int code;
        const char *msg;
    } errors[] = {
            {TA_LIB_NOT_INITIALIZE,        "Lib not initialized"},
            {TA_BAD_PARAM,                 "Bad parameter: A parameter is out of range"},
            {TA_ALLOC_ERR,                 "Allocation error"},
            {TA_GROUP_NOT_FOUND,           "Group not found"},
            {TA_FUNC_NOT_FOUND,            "Function not found"},
            {TA_INVALID_HANDLE,            "Invalid handle"},
            {TA_INVALID_PARAM_HOLDER,      "Invalid parameter holder"},
            {TA_INVALID_PARAM_HOLDER_TYPE, "Invalid param holder type"},
            {TA_INVALID_PARAM_FUNCTION,    "Invalid parameter function"},
            {TA_OUTPUT_NOT_ALL_INITIALIZE, "Output not all initialized"},
            {TA_OUT_OF_RANGE_END_INDEX,    "Out of range end index"},
            {TA_OUT_OF_RANGE_START_INDEX,  "Out of range start index"},
            {TA_INPUT_NOT_ALL_INITIALIZE,  "Input not all initialize"},
            {TA_INVALID_LIST_TYPE,         "Invalid list type"},
            {TA_BAD_OBJECT,                "Bad object"},
            {TA_NOT_SUPPORTED,             "Not supported"},
            {TA_INTERNAL_ERROR,            "Internal error"},
            {TA_UNKNOWN_ERR,               "Unknown error"},
    };

    for (int i = 0; i < sizeof(errors); i++)
    {
        if (errors[i].code == retCode)
        {
            throw TaLibImplException(errors[i].code, errors[i].msg);
        }
    }

    throw TaLibImplException(retCode, "unknown_error");
}
