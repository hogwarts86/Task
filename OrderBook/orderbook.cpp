#include "orderbook.h"

void OrderBook::addAsk(int ammount, float price){
    add(ammount,price,false);
}

void OrderBook::addBid(int ammount, float price){
    add(ammount,price,true);
}

void OrderBook::add(int ammount, float price, bool isBid){
    if(isBid)
        bids[price]+= ammount;
    else
        asks[price]+= ammount;
}

void OrderBook::removeBid(int ammount, float price){
     remove(ammount,price,true);
}

void OrderBook::removeAsk(int ammount,float price){
    remove(ammount,price,false);
}

void OrderBook::remove(int ammount, float price, bool isBid){
    auto &table = isBid ? bids : asks;
    auto it  = table.find(price);
    if(it != table.end()){
        it->second -= ammount;
        if(it-> second == 0)
            table.erase(it);
    }
}

OrderBook::BidAsk OrderBook::getBidAsk(){
    BidAsk result;
    auto bestBid = bids.rbegin();
    if(bestBid != bids.rend())
        result.bid = *bestBid;
    
    auto bestAsk = asks.begin();
    if(bestAsk != asks.end())
        result.ask = *bestAsk;

    return result;

}

std::ostream& operator << (std::ostream &os, const OrderBook::BidAsk &bidAsk)
{
    auto print = [&](const OrderBook::BidAsk::Entry e, const std::string &text)
    {
        bool have_value = e.is_initialized();
        if(have_value)
        {
            auto value = e.get();
            os << value.second << text << " @"<< value.first;
        }else{
            os << "NO "<< text;
        }
    };

    print(bidAsk.bid,"BUY");
    os<< ", ";
    print(bidAsk.ask,"SELL");
    return os;

}


std::ostream& operator << (std::ostream &os, const OrderBook &book)
{
    if(book.isEmpty())
    {
        os << "ORDER BOOK EMPTY";
        return os;
    }

    for(auto it = book.asks.rbegin(); it!= book.asks.rend(); ++it)
        os << it->first<<"\t"<<it->second<< std::endl;
        os << std::endl;
    for(auto it = book.bids.rbegin(); it!= book.bids.rend(); ++it)
        os << it->first<<"\t"<<it->second<< std::endl;
    return os;

}