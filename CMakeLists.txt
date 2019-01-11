cmake_minimum_required(VERSION 3.12)
project(trader)

set(CMAKE_CXX_STANDARD 17)

include_directories(inc)
include_directories(src)

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
        ${CMAKE_CURRENT_LIST_DIR}/inc/ifc/ICommand.h inc/Command.h)

set(sources
        ${CMAKE_CURRENT_LIST_DIR}/src/IEX.cpp)

add_executable(trader main.cpp ${sources} ${headers})
target_link_libraries(trader jsoncpp)
target_link_libraries(trader curl)
target_link_libraries(trader /usr/share/boost-build)
