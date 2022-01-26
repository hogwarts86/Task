#include <gtest/gtest.h>
#include "orderbook.h"

TEST(OrderBookTest, OrderBookEmptyTest){
    OrderBook book;
    EXPECT_TRUE(book.isEmpty());
}

TEST(OderBookTest, OrderBookAddBidTest){
    OrderBook book;
    book.addBid(10,100.00);
    auto bidAsk = book.getBidAsk();
    EXPECT_TRUE(bidAsk.bid.is_initialized());
    auto bid = bidAsk.bid.get();
    EXPECT_EQ(100.00,bid.first); //Test the price as float number
    EXPECT_EQ(10,bid.second);  //Test the ammount as int number
}