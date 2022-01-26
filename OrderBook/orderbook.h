#pragma once

#include <map>
#include <iostream>
#include <boost/optional.hpp>

class OrderBook{
    std::map<float,int> bids,asks;

    void add(int ammount, float price, bool isBid);
    void remove(int ammount, float price, bool isBid);

public:
    struct BidAsk{
        typedef boost::optional<std::pair<float,int>> Entry;
        Entry bid, ask;
        boost::optional<float>spread() const;
    };

    inline bool isEmpty() const{
        return bids.empty() && asks.empty();
    };
    void addBid(int ammount, float price);
    void addAsk(int ammount, float price);

    void removeBid(int ammount, float price);
    void removeAsk(int ammount, float price);

    BidAsk getBidAsk();


    friend std::ostream& operator << (std::ostream &os, const OrderBook &book);
    friend std::ostream& operator << (std::ostream &os, const BidAsk &ba);
};