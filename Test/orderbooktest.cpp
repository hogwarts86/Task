#include <gtest/gtest.h>
#include "orderbook.h"
#define GTEST_COUT std::cerr << "[          ] [ INFO ]"
TEST(OrderBookTest, OrderBookEmptyTest){
    OrderBook book;
    EXPECT_TRUE(book.isEmpty());
}

TEST(OrderBookTest, OrderBookAddBidTest){
    OrderBook book;
    book.addBid(10,100.00);
    auto bidAsk = book.getBidAsk();
    EXPECT_TRUE(bidAsk.bid.is_initialized());
    auto bid = bidAsk.bid.get();
    EXPECT_EQ(100.00,bid.first); //Test the price as float number
    EXPECT_EQ(10,bid.second);  //Test the ammount as int number
}

TEST(OrderBookTest, OrderBookRemovalTest){
    OrderBook book;
    book.addBid(10,200.00);
    book.addAsk(50,150.00);
    book.removeBid(5,200.00);
    book.removeAsk(15,150.00);
    auto bidAsk = book.getBidAsk();
    EXPECT_TRUE(bidAsk.bid.is_initialized());
    EXPECT_TRUE(bidAsk.ask.is_initialized());
    auto bid = bidAsk.bid.get();
    auto ask = bidAsk.ask.get();
    
    EXPECT_EQ(200.00, bid.first);
    EXPECT_EQ(5,bid.second);

    EXPECT_EQ(150.00, ask.first);
    EXPECT_EQ(35,ask.second);
}

TEST(OrderBookTest, OrderBookPrintTest)
{
    OrderBook book;
    book.addBid(10,110.00);
    book.addBid(30,100.00);
    book.addAsk(50,300.00);
}