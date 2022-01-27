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


add_library(orderbook ${SOURCES} ${HEADERS})