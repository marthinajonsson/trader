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

include_directories(thread_engine)
include_directories(FA)
include_directories(FA_unittest)
include_directories(TA)
include_directories(TA/TA_unittest)
include_directories(io)
include_directories(io_unittest)
include_directories(comm)
include_directories(comm_unittest)
include_directories(utils)
include_directories(ifc)
include_directories(external/gtest/googlemock)
include_directories( ${Boost_INCLUDE_DIR} )
include_directories( ${Boost_LIB_DIR} )
include_directories(${JsonStreamer_INCLUDE_DIRS})

set(utils
        ${CMAKE_CURRENT_LIST_DIR}/utils/Util.h
        ${CMAKE_CURRENT_LIST_DIR}/utils/Exceptions.h)

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
        ${CMAKE_CURRENT_LIST_DIR}/ifc/Borsdata.h
        ${CMAKE_CURRENT_LIST_DIR}/ifc/Borsdata.cpp)
        #${CMAKE_CURRENT_LIST_DIR}/ifc/IEX.h
        #${CMAKE_CURRENT_LIST_DIR}/ifc/IEX.cpp)

set(comm
        ${CMAKE_CURRENT_LIST_DIR}/comm/Client.h
        ${CMAKE_CURRENT_LIST_DIR}/comm/Client.cpp
        )

set(TA
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
        ${CMAKE_CURRENT_LIST_DIR}/TA/ADXAnalyzer.h
        ${CMAKE_CURRENT_LIST_DIR}/TA/ADXAnalyzer.cpp
        ${CMAKE_CURRENT_LIST_DIR}/TA/SMAAnalyzer.h
        ${CMAKE_CURRENT_LIST_DIR}/TA/SMAAnalyzer.cpp )

set(FA ${CMAKE_CURRENT_LIST_DIR}/FA/PE.cpp
        ${CMAKE_CURRENT_LIST_DIR}/FA/PE.h
        )

set(main
        ${CMAKE_CURRENT_LIST_DIR}/InputParser.h
        ${CMAKE_CURRENT_LIST_DIR}/main.h
        ${CMAKE_CURRENT_LIST_DIR}/main.cpp
        ${CMAKE_CURRENT_LIST_DIR}/test_main.cpp
        ${CMAKE_CURRENT_LIST_DIR}/TestStartup.h
        )

enable_testing()
add_subdirectory(external/gtest/googlemock)

add_executable(trader ${main} ${FA} ${TA} ${thread_engine} ${io} ${ifc} ${utils} ${comm})

target_link_libraries(trader ${Boost_LIBRARIES})
target_link_libraries(trader jsoncpp)
target_link_libraries(trader gmock_main)
target_link_libraries(trader curl)
target_link_libraries(trader ssl)
target_link_libraries(trader pthread)

