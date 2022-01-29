#include <gtest/gtest.h>
#include "orderbook.h"
#include "finstrument.h"
#include "json.hpp"
#include <fstream>


#define GTEST_COUT std::cerr << "[          ] [ INFO ]"


//OrderBookOnEmptyTest
TEST(OrderBookTest, OrderBookEmptyTest){
    OrderBook book;
    EXPECT_TRUE(book.isEmpty());
}
//OrderBookOnEmptyTest
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

    EXPECT_TRUE(book.findPriceInBidTable(200.00));
}

TEST(FInstrumentTest, FInstrumentTest)
{   
    FInstrument fInstrument;
    std::string fileName = "../../Output/FileTest01.txt";
    std::string content = "This is content\n";
    fInstrument.printToFile(fileName,content);

    std::string line;
    std::ifstream in(fileName);
    while(in>>std::ws && std::getline(in,line))
    ;
    EXPECT_EQ("This is content",line);
    
}

TEST(FInstrumentTest, FInstrumentSetName){
    FInstrument fInstrument("HHAA");
    EXPECT_EQ("HHAA",fInstrument.getInstrumentName());
}

TEST(FInstrumentTest,ParseJSONTest){
    FInstrument fInstrument;
    std::ifstream input("../../Test/test.json",std::ios::in);
    json jf;
    input>>jf;
    std::string bookOrder = jf.begin().key();
    EXPECT_EQ("book",bookOrder);
    
    // fInstrument.parseJSONObject(jf,bot,bookOrder);
    // Get Symbols from JSON
    std::string symbol = jf[bookOrder]["symbol"];
    EXPECT_EQ("20",symbol);
    
}

TEST(FInstrumentTest,NormalizedPrice){
    double price = 23943.3300000000;
    FInstrument fInstrument;
    std::string str= fInstrument.normalizePrice(price);
    EXPECT_EQ("23,943.33",str);
    
}
