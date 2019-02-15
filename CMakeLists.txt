cmake_minimum_required(VERSION 3.12)
project(trader)

set(CMAKE_CXX_STANDARD 17)


find_package(OpenSSL)
find_package( Boost 1.69 COMPONENTS REQUIRED )

find_library(/usr/local/lib ta-lib libta-lib.a)


include_directories(inc)
include_directories(src)
include_directories(unittest)
include_directories(external/gtest/googlemock)
include_directories(../../thirdlibs/ta-lib/include)
include_directories( ${Boost_INCLUDE_DIR} )
include_directories( ${Boost_LIB_DIR} )


set(headers
        ${CMAKE_CURRENT_LIST_DIR}/inc/IEX.h
        ${CMAKE_CURRENT_LIST_DIR}/inc/StockInfo.h
        ${CMAKE_CURRENT_LIST_DIR}/inc/Util.h
        ${CMAKE_CURRENT_LIST_DIR}/inc/InputParser.h
        ${CMAKE_CURRENT_LIST_DIR}/unittest/TestStartup.h
        ${CMAKE_CURRENT_LIST_DIR}/inc/AlgoContext.h
        ${CMAKE_CURRENT_LIST_DIR}/inc/TaLib.h
        ${CMAKE_CURRENT_LIST_DIR}/inc/WebSocket.h
        ${CMAKE_CURRENT_LIST_DIR}/inc/Exceptions.h
        ${CMAKE_CURRENT_LIST_DIR}/inc/main.h)

set(sources
        ${CMAKE_CURRENT_LIST_DIR}/src/IEX.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/IEXStock.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/IEXRef.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/TaLib.cpp
        ${CMAKE_CURRENT_LIST_DIR}/unittest/RequestTest.cpp
        ${CMAKE_CURRENT_LIST_DIR}/test_main.cpp)

enable_testing()
add_subdirectory(external/gtest/googlemock)


add_executable(trader main.cpp ${sources} ${headers})


target_link_libraries(trader jsoncpp)
target_link_libraries(trader gmock_main)
target_link_libraries(trader curl)
target_link_libraries(trader ${ta-lib})
target_link_libraries(trader ${Boost_LIBRARIES})
