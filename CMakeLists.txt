cmake_minimum_required(VERSION 3.7...3.18)
set (This AppOrderBook)

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
#enable_testing()
add_subdirectory(OrderBook)
include_directories(OrderBook)
target_link_libraries(${This} PRIVATE orderbook)

enable_testing()
add_subdirectory(external/)
add_subdirectory(Test)