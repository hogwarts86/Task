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