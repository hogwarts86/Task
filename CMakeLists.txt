cmake_minimum_required(VERSION 3.7...3.18)
set (This OrderBook)

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
#add_subdirectory(googletest)
#add_subdirectory(test)