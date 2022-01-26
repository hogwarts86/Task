cmake_minimum_required(VERSION 3.7...3.18)
set (This AppOrderBook)
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
find_package(Boost 1.74.0 REQUIRED)
if(Boost_FOUND)
  include_directories(
    src
    ${Boost_INCLUDE_DIRS}
    ${Boost_LIBRARY_DIRS}
    )
endif()

add_subdirectory(OrderBook)
include_directories(
        OrderBook 
        ${Boost_INCLUDE_DIR}
)
target_link_libraries(${This} 
        PRIVATE orderbook
        PUBLIC  ${Boost_LIBRARIES}
        )

enable_testing()
add_subdirectory(external/)
add_subdirectory(Test)