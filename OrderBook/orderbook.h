#pragma once

#include <map>
#include <iostream>
#include <boost/optional.hpp>

class OrderBook{
    std::map<double,int> bids,asks;
    void add(int ammount, double price, bool isBid);
    void remove(int ammount, double price, bool isBid);

public:

    struct BidAsk{
        typedef boost::optional<std::pair<double,int>> Entry;
        Entry bid, ask;
        boost::optional<double>spread() const;
    };

    inline bool isEmpty() const{
        return bids.empty() && asks.empty();
    };
    void addBid(int ammount, double price);
    void addAsk(int ammount, double price);

    void removeBid(int ammount, double price);
    void removeAsk(int ammount, double price);

    BidAsk getBidAsk();


    friend std::ostream& operator << (std::ostream &os, const OrderBook &book);
    friend std::ostream& operator << (std::ostream &os, const BidAsk &ba);
    
};