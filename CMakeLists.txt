cmake_minimum_required(VERSION 3.12)
project(trader)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "../json_streamer/cmake-build-debug")
set(JsonStreamer_INCLUDE_DIRS ../json_streamer/src/)
set(LOCAL_LIB_DIRS ${LOCAL_LIB_DIRS} /usr/local/lib)
set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(OpenSSL)
find_package( Boost 1.69 COMPONENTS REQUIRED filesystem)
find_package(Threads REQUIRED)

include_directories(api)
include_directories(analysis)
include_directories(borsdata)
include_directories(configuration)
include_directories(thread_engine)
include_directories(FA)
include_directories(FA_unittest)
include_directories(TA)
include_directories(TA/TA_unittest)
include_directories(io)
include_directories(model)
include_directories(io_unittest)
include_directories(comm)
include_directories(comm_unittest)
include_directories(utils)
include_directories(ifc)
include_directories(external/gtest/googlemock)
include_directories( ${Boost_INCLUDE_DIR} )
include_directories( ${Boost_LIB_DIR} )
include_directories(${JsonStreamer_INCLUDE_DIRS})

set(analysis ${CMAKE_CURRENT_LIST_DIR}/analysis/ADXAnalyzer.h
        ${CMAKE_CURRENT_LIST_DIR}/analysis/ADXAnalyzer.cpp
        ${CMAKE_CURRENT_LIST_DIR}/analysis/SMAAnalyzer.h
        ${CMAKE_CURRENT_LIST_DIR}/analysis/SMAAnalyzer.cpp
        ${CMAKE_CURRENT_LIST_DIR}/analysis/InstrumentMetaAnalyzer.cpp
        ${CMAKE_CURRENT_LIST_DIR}/analysis/InstrumentMetaAnalyzer.h
        ${CMAKE_CURRENT_LIST_DIR}/analysis/InstrumentAnalyzer.cpp
        ${CMAKE_CURRENT_LIST_DIR}/analysis/InstrumentAnalyzer.h
        ${CMAKE_CURRENT_LIST_DIR}/analysis/ReportAnalyzer.cpp
        ${CMAKE_CURRENT_LIST_DIR}/analysis/ReportAnalyzer.h
        ${CMAKE_CURRENT_LIST_DIR}/analysis/KpisAnalyzer.cpp
        ${CMAKE_CURRENT_LIST_DIR}/analysis/KpisAnalyzer.h
        ${CMAKE_CURRENT_LIST_DIR}/analysis/StockPriceAnalyzer.cpp
        ${CMAKE_CURRENT_LIST_DIR}/analysis/StockPriceAnalyzer.h
        ${CMAKE_CURRENT_LIST_DIR}/analysis/StockSplitAnalyzer.cpp
        ${CMAKE_CURRENT_LIST_DIR}/analysis/StockSplitAnalyzer.h)

set(borsdata ${CMAKE_CURRENT_LIST_DIR}/borsdata/Instruments.h
        ${CMAKE_CURRENT_LIST_DIR}/borsdata/Instruments.cpp
        ${CMAKE_CURRENT_LIST_DIR}/borsdata/InstrumentsMeta.h
        ${CMAKE_CURRENT_LIST_DIR}/borsdata/InstrumentsMeta.cpp
        ${CMAKE_CURRENT_LIST_DIR}/borsdata/StockPrices.h
        ${CMAKE_CURRENT_LIST_DIR}/borsdata/StockPrices.cpp
        ${CMAKE_CURRENT_LIST_DIR}/borsdata/StockSplits.cpp
        ${CMAKE_CURRENT_LIST_DIR}/borsdata/StockSplits.h
        ${CMAKE_CURRENT_LIST_DIR}/borsdata/Reports.cpp
        ${CMAKE_CURRENT_LIST_DIR}/borsdata/Reports.h
        ${CMAKE_CURRENT_LIST_DIR}/borsdata/Kpis.cpp
        ${CMAKE_CURRENT_LIST_DIR}/borsdata/Kpis.h)

set(model ${CMAKE_CURRENT_LIST_DIR}/model/BranchesRespV1.h
        ${CMAKE_CURRENT_LIST_DIR}/model/BranchV1.h
        ${CMAKE_CURRENT_LIST_DIR}/model/CountryV1.h
        ${CMAKE_CURRENT_LIST_DIR}/model/CountriesRespV1.h
        ${CMAKE_CURRENT_LIST_DIR}/model/MarketV1.h
        ${CMAKE_CURRENT_LIST_DIR}/model/MarketsRespV1.h
        ${CMAKE_CURRENT_LIST_DIR}/model/SectorV1.h
        ${CMAKE_CURRENT_LIST_DIR}/model/SectorsRespV1.h
        ${CMAKE_CURRENT_LIST_DIR}/model/InstrumentV1.h
        ${CMAKE_CURRENT_LIST_DIR}/model/InstrumentRespV1.h
        ${CMAKE_CURRENT_LIST_DIR}/model/InstrumentUpdatedV1.h
        ${CMAKE_CURRENT_LIST_DIR}/model/InstrumentUpdatedRespV1.h
        ${CMAKE_CURRENT_LIST_DIR}/model/KpiV1.h
        ${CMAKE_CURRENT_LIST_DIR}/model/KpisRespV1.h
        ${CMAKE_CURRENT_LIST_DIR}/model/KpisAllCompRespV1.h
        ${CMAKE_CURRENT_LIST_DIR}/model/KpiHistoryV1.h
        ${CMAKE_CURRENT_LIST_DIR}/model/KpisHistoryRespV1.h
        ${CMAKE_CURRENT_LIST_DIR}/model/KpisCalcUpdatedRespV1.h
        ${CMAKE_CURRENT_LIST_DIR}/model/ReportV1.h
        ${CMAKE_CURRENT_LIST_DIR}/model/ReportsRespV1.h
        ${CMAKE_CURRENT_LIST_DIR}/model/ReportsCompoundRespV1.h
        ${CMAKE_CURRENT_LIST_DIR}/model/StockPriceV1.h
        ${CMAKE_CURRENT_LIST_DIR}/model/StockPricesRespV1.h
        ${CMAKE_CURRENT_LIST_DIR}/model/StockPricesLastRespV1.h
        ${CMAKE_CURRENT_LIST_DIR}/model/StockSplitV1.h
        ${CMAKE_CURRENT_LIST_DIR}/model/StockSplitRespV1.h)


set(api ${CMAKE_CURRENT_LIST_DIR}/api/IBorsdata.h
        ${CMAKE_CURRENT_LIST_DIR}/api/InstrumentsApi.cpp
        ${CMAKE_CURRENT_LIST_DIR}/api/IInstrumentsApi.h
        ${CMAKE_CURRENT_LIST_DIR}/api/IInstrumentsMetaApi.h
        ${CMAKE_CURRENT_LIST_DIR}/api/InstrumentsMetaApi.cpp
        ${CMAKE_CURRENT_LIST_DIR}/api/IKpisApi.h
        ${CMAKE_CURRENT_LIST_DIR}/api/KpisApi.cpp
        ${CMAKE_CURRENT_LIST_DIR}/api/IReportsApi.h
        ${CMAKE_CURRENT_LIST_DIR}/api/ReportsApi.cpp
        ${CMAKE_CURRENT_LIST_DIR}/api/IStockPricesApi.h
        ${CMAKE_CURRENT_LIST_DIR}/api/StockPricesApi.cpp
        ${CMAKE_CURRENT_LIST_DIR}/api/IStockSplitsApi.h
        ${CMAKE_CURRENT_LIST_DIR}/api/StockSplitsApi.cpp
        ${CMAKE_CURRENT_LIST_DIR}/api_unittest/InstrumentsApiTest.cpp
        ${CMAKE_CURRENT_LIST_DIR}/api/InstrumentsMetaApi.h
        ${CMAKE_CURRENT_LIST_DIR}/api/InstrumentsApi.h
        ${CMAKE_CURRENT_LIST_DIR}/api/ReportsApi.h
        ${CMAKE_CURRENT_LIST_DIR}/api_unittest/ReportsApiTest.cpp
        ${CMAKE_CURRENT_LIST_DIR}/api_unittest/StockSplitsTest.cpp
        ${CMAKE_CURRENT_LIST_DIR}/api/StockSplitsApi.h
        ${CMAKE_CURRENT_LIST_DIR}/api/StockPricesApi.h
        ${CMAKE_CURRENT_LIST_DIR}/api/KpisApi.h
        ${CMAKE_CURRENT_LIST_DIR}/api_unittest/StockPricesTest.cpp
        ${CMAKE_CURRENT_LIST_DIR}/api_unittest/KpisApiTest.cpp
        ${CMAKE_CURRENT_LIST_DIR}/api_unittest/InstrumentsMetaApiTest.cpp)

set(utils
        ${CMAKE_CURRENT_LIST_DIR}/utils/Util.h
        ${CMAKE_CURRENT_LIST_DIR}/utils/Exceptions.h)

set(configuration
        ${CMAKE_CURRENT_LIST_DIR}/configuration/ApiConfiguration.h)

set(thread_engine
        ${CMAKE_CURRENT_LIST_DIR}/thread_engine/ActiveAlgorithm.h
        ${CMAKE_CURRENT_LIST_DIR}/thread_engine/AlgoQueue.h
        ${CMAKE_CURRENT_LIST_DIR}/thread_engine/AlgoDispatcher.h)

set(io
        ${CMAKE_CURRENT_LIST_DIR}/io_unittest/SearchJsonTest.cpp
        ${CMAKE_CURRENT_LIST_DIR}/io/SearchJson.h
        ${CMAKE_CURRENT_LIST_DIR}/io/CSVWriter.h
        ${CMAKE_CURRENT_LIST_DIR}/io/CSVWriter.cpp
        ${CMAKE_CURRENT_LIST_DIR}/io/JsonWriter.h
        ${CMAKE_CURRENT_LIST_DIR}/io/JsonWriter.cpp
        ${CMAKE_CURRENT_LIST_DIR}/io/Interests.h
        ${CMAKE_CURRENT_LIST_DIR}/io/Interests.cpp)

set(ifc
        ${CMAKE_CURRENT_LIST_DIR}/ifc/UniBit.h
        ${CMAKE_CURRENT_LIST_DIR}/ifc/UniBit.cpp
        ${CMAKE_CURRENT_LIST_DIR}/ifc/Observer.h
        ${CMAKE_CURRENT_LIST_DIR}/ifc/Subject.h
        ${CMAKE_CURRENT_LIST_DIR}/ifc/Subject.cpp
        ${CMAKE_CURRENT_LIST_DIR}/ifc/Analyzer.h
        )

set(comm
        ${CMAKE_CURRENT_LIST_DIR}/comm/Client.h
        ${CMAKE_CURRENT_LIST_DIR}/comm/Client.cpp
        )

set(algo
        ${CMAKE_CURRENT_LIST_DIR}/TA/SMA.h
        ${CMAKE_CURRENT_LIST_DIR}/TA/SMA.cpp
        ${CMAKE_CURRENT_LIST_DIR}/TA/ADX.h
        ${CMAKE_CURRENT_LIST_DIR}/TA/ADX.cpp
        ${CMAKE_CURRENT_LIST_DIR}/TA/RSI.cpp
        ${CMAKE_CURRENT_LIST_DIR}/TA/RSI.h
        #${CMAKE_CURRENT_LIST_DIR}/TA/DeepLearning.h
        # ${CMAKE_CURRENT_LIST_DIR}/TA/DeepLearning.cpp
        ${CMAKE_CURRENT_LIST_DIR}/TA/ProcessHandler.h
        ${CMAKE_CURRENT_LIST_DIR}/TA/ProcessHandler.cpp
        ${CMAKE_CURRENT_LIST_DIR}/TA/Algorithm.h
        ${CMAKE_CURRENT_LIST_DIR}/FA/PE.cpp
        ${CMAKE_CURRENT_LIST_DIR}/FA/PE.h)

set(main
        ${CMAKE_CURRENT_LIST_DIR}/InputParser.h
        ${CMAKE_CURRENT_LIST_DIR}/main.h
        ${CMAKE_CURRENT_LIST_DIR}/main.cpp
        ${CMAKE_CURRENT_LIST_DIR}/test_main.cpp
        ${CMAKE_CURRENT_LIST_DIR}/TestStartup.h)

enable_testing()
add_subdirectory(external/gtest/googlemock)

add_executable(trader ${main} ${algo} ${thread_engine} ${io} ${ifc} ${utils} ${comm} ${api} ${model} ${borsdata} ${configuration} ${analysis})

target_link_libraries(trader ${Boost_LIBRARIES})
target_link_libraries(trader jsoncpp)
target_link_libraries(trader gmock_main)
target_link_libraries(trader curl)
target_link_libraries(trader ssl)
target_link_libraries(trader pthread)

