set(This OrderBookTest)

set(Sources 
    orderbooktest.cpp 
)

set(CXX_FLAGS
    -g
    -Wall
)

include_directories(
    ${AppOrderBook_SOURCE_DIR}/OrderBook
    ../ext/json/single_include/nlohmann
    )
add_executable(
    ${This} ${Sources}
)

target_include_directories(
    ${This} PUBLIC OrderBook PUBLIC external ${Boost_INCLUDE_DIR}
    PUBLIC ${PROJECT_SOURCE_DIR}/ext/json/single_include/nlohmann
)
target_link_libraries(
    ${This} PUBLIC gtest_main 
    PUBLIC  ${Boost_LIBRARIES}
    PUBLIC orderbook    
    PRIVATE nlohmann_json::nlohmann_json 
)



