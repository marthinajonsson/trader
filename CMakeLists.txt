cmake_minimum_required(VERSION 3.12)
project(trader)

set(CMAKE_CXX_STANDARD 17)
set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(OpenSSL)
find_package( Boost 1.69 COMPONENTS REQUIRED )
find_package(Threads REQUIRED)
find_library(/usr/local/lib ta-lib libta-lib.a)

# DOXYGEN
find_package(Doxygen)
if(DOXYGEN_FOUND)

    set(DOXYGEN_INPUT ${CMAKE_CURRENT_LIST_DIR}/docs/doxy.config)
    set(DOXYGEN_OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
    message(STATUS, ${DOXYGEN_INPUT})
    message(STATUS, ${DOXYGEN_OUTPUT})
    add_custom_command(
            OUTPUT ${DOXYGEN_OUTPUT}
            COMMAND ${CMAKE_COMMAND} -E echo_append "Building API Documentation..."
            COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_INPUT}
            COMMAND ${CMAKE_COMMAND} -E echo "Done."
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
            DEPENDS ${DOXYGEN_INPUT}
    )

    add_custom_target(apidoc ALL DEPENDS ${DOXYGEN_OUTPUT})

    add_custom_target(apidoc_forced
            COMMAND ${CMAKE_COMMAND} -E echo_append "Building API Documentation..."
            COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_INPUT}
            COMMAND ${CMAKE_COMMAND} -E echo "Done."
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
            )

endif(DOXYGEN_FOUND)


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
        ${CMAKE_CURRENT_LIST_DIR}/inc/ActiveAlgorithm.h
        ${CMAKE_CURRENT_LIST_DIR}/inc/AlgoQueue.h
        ${CMAKE_CURRENT_LIST_DIR}/inc/DeepLearning.h
        ${CMAKE_CURRENT_LIST_DIR}/inc/Exceptions.h
        ${CMAKE_CURRENT_LIST_DIR}/inc/main.h inc/AlgoDispatcher.h inc/MeanReversion.h)

set(sources
        ${CMAKE_CURRENT_LIST_DIR}/src/IEX.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/IEXStock.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/IEXRef.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/DeepLearning.cpp
        ${CMAKE_CURRENT_LIST_DIR}/unittest/RequestTest.cpp
        ${CMAKE_CURRENT_LIST_DIR}/test_main.cpp src/MeanReversion.cpp)

enable_testing()
add_subdirectory(external/gtest/googlemock)


add_executable(trader main.cpp ${sources} ${headers})


target_link_libraries(trader jsoncpp)
target_link_libraries(trader gmock_main)
target_link_libraries(trader curl)
target_link_libraries(trader ${ta-lib})
target_link_libraries(trader ${Boost_LIBRARIES})
