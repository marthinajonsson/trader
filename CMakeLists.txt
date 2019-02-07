cmake_minimum_required(VERSION 3.12)
project(trader)

set(CMAKE_CXX_STANDARD 17)

include_directories(inc)
include_directories(src)
include_directories(external/gtest/googlemock)

find_package(OpenSSL)

set(externals
        ${CMAKE_CURRENT_LIST_DIR}/external/IEX/GetSetClearTA.cpp
        ${CMAKE_CURRENT_LIST_DIR}/external/IEX/IEX.cpp
        ${CMAKE_CURRENT_LIST_DIR}/external/IEX/IEX.h
        ${CMAKE_CURRENT_LIST_DIR}/external/IEX/JSONdata.cpp
        ${CMAKE_CURRENT_LIST_DIR}/external/IEX/JSONdata.h
        ${CMAKE_CURRENT_LIST_DIR}/external/IEX/main.h

        ${CMAKE_CURRENT_LIST_DIR}/external/IEX/TechnicalAnalysis.cpp
        ${CMAKE_CURRENT_LIST_DIR}/external/IEX/TechnicalAnalysis.h
        )

set(headers
        ${CMAKE_CURRENT_LIST_DIR}/inc/IEX.h
        ${CMAKE_CURRENT_LIST_DIR}/inc/StockInfo.h
        ${CMAKE_CURRENT_LIST_DIR}/inc/Util.h)

set(sources
        ${CMAKE_CURRENT_LIST_DIR}/src/IEX.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/IEXStock.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/IEXRef.cpp unittest/HTMLRequestTest.cpp)

enable_testing()
add_subdirectory(external/gtest/googlemock)


add_executable(trader main.cpp ${sources} ${headers})


target_link_libraries(trader jsoncpp)
target_link_libraries(trader gmock_main)
target_link_libraries(trader curl)
target_link_libraries(trader /usr/share/boost-build)
