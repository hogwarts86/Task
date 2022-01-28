cmake_minimum_required(VERSION 3.7...3.18)
set(This AppOrderBook)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(${This})
set(CXX_FLAGS
-g
-Wall
)

set (SOURCES
    main.cpp
)

set (HEADERS
)
add_executable(${This} ${SOURCES} ${HEADERS})

#include boost directory
find_package(Boost 1.74.0 REQUIRED)
if(Boost_FOUND)
  include_directories(
    ${Boost_INCLUDE_DIRS}
    ${Boost_LIBRARY_DIRS}
    )
endif()

add_subdirectory(OrderBook)

include_directories(
        OrderBook
        ${PROJECT_SOURCE_DIR}/ext/json/single_include/nlohmann
)
target_link_libraries(${This} 
        PRIVATE orderbook
        PUBLIC  ${Boost_LIBRARIES}
        PRIVATE nlohmann_json::nlohmann_json
        )

enable_testing()
add_subdirectory(${PROJECT_SOURCE_DIR}/external)
add_subdirectory(${PROJECT_SOURCE_DIR}/ext/json)
add_subdirectory(Test)