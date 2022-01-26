#include "orderbook.h"


bool OrderBook::isEmpty(){
    return bids.empty() && asks.empty();
}


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