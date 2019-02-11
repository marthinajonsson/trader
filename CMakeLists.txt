cmake_minimum_required(VERSION 3.12)
project(trader)

set(CMAKE_CXX_STANDARD 17)

include_directories(inc)
include_directories(src)
include_directories(unittest)
include_directories(external/gtest/googlemock)

find_package(OpenSSL)

set(headers
        ${CMAKE_CURRENT_LIST_DIR}/inc/IEX.h
        ${CMAKE_CURRENT_LIST_DIR}/inc/StockInfo.h
        ${CMAKE_CURRENT_LIST_DIR}/inc/Util.h
        ${CMAKE_CURRENT_LIST_DIR}/inc/InputParser.h
        ${CMAKE_CURRENT_LIST_DIR}/unittest/TestStartup.h)

set(sources
        ${CMAKE_CURRENT_LIST_DIR}/src/IEX.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/IEXStock.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/IEXRef.cpp
        ${CMAKE_CURRENT_LIST_DIR}/unittest/RequestTest.cpp
        ${CMAKE_CURRENT_LIST_DIR}/test_main.cpp)

enable_testing()
add_subdirectory(external/gtest/googlemock)


add_executable(trader main.cpp ${sources} ${headers})


target_link_libraries(trader jsoncpp)
target_link_libraries(trader gmock_main)
target_link_libraries(trader curl)
target_link_libraries(trader /usr/share/boost-build)
