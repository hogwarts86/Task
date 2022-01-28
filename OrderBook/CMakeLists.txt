set(SOURCES
    orderbook.cpp
    inputjsonparser.cpp
    finstrument.cpp
    )
set(HEADERS 
    orderbook.h
    inputjsonparser.h
    finstrument.h
    )
include_directories(
        ../ext/json/single_include/nlohmann
)

add_library(orderbook ${SOURCES} ${HEADERS})