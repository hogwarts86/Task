set(This OrderBookTest)

set(Sources orderbooktest.cpp)

set(CXX_FLAGS
    -g
    -Wall
)

include_directories(
    ${AppOrderBook_SOURCE_DIR}/OrderBook

    )
add_executable(
    ${This} ${Sources}
)

target_include_directories(
    ${This} PUBLIC OrderBook PUBLIC external/
)
target_link_libraries(
    ${This} PUBLIC gtest_main PUBLIC orderbook
)


