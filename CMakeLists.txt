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

include_directories(h)
include_directories(ifc)
include_directories(src)
include_directories(unittest)
include_directories(external/gtest/googlemock)
include_directories( ${Boost_INCLUDE_DIR} )
include_directories( ${Boost_LIB_DIR} )
include_directories(${JsonStreamer_INCLUDE_DIRS})

set(headers
        ${CMAKE_CURRENT_LIST_DIR}/ifc/IEX.h
        ${CMAKE_CURRENT_LIST_DIR}/h/Util.h
        ${CMAKE_CURRENT_LIST_DIR}/h/InputParser.h
        ${CMAKE_CURRENT_LIST_DIR}/h/ActiveAlgorithm.h
        ${CMAKE_CURRENT_LIST_DIR}/h/AlgoQueue.h
        ${CMAKE_CURRENT_LIST_DIR}/h/DeepLearning.h
        ${CMAKE_CURRENT_LIST_DIR}/h/Exceptions.h
        ${CMAKE_CURRENT_LIST_DIR}/h/main.h
        ${CMAKE_CURRENT_LIST_DIR}/h/AlgoDispatcher.h
        ${CMAKE_CURRENT_LIST_DIR}/ifc/UniBit.h
        ${CMAKE_CURRENT_LIST_DIR}/h/Client.h
        ${CMAKE_CURRENT_LIST_DIR}/h/ADX.h
        ${CMAKE_CURRENT_LIST_DIR}/h/SearchJson.h
        ${CMAKE_CURRENT_LIST_DIR}/h/CSVWriter.h
        ${CMAKE_CURRENT_LIST_DIR}/h/JsonWriter.h)

set(sources
        ${CMAKE_CURRENT_LIST_DIR}/ifc/IEX.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/DeepLearning.cpp
        ${CMAKE_CURRENT_LIST_DIR}/ifc/UniBit.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/ADX.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/JsonWriter.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/Client.cpp)

set(tests
        ${CMAKE_CURRENT_LIST_DIR}/test_main.cpp
        ${CMAKE_CURRENT_LIST_DIR}/unittest/TestStartup.h
        ${CMAKE_CURRENT_LIST_DIR}/unittest/RequestTest.cpp)

enable_testing()
add_subdirectory(external/gtest/googlemock)

add_executable(trader main.cpp ${sources} ${headers} ${tests})

target_link_libraries(trader ${Boost_LIBRARIES})
target_link_libraries(trader jsoncpp)
target_link_libraries(trader gmock_main)
target_link_libraries(trader curl)
