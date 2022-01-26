#pragma once

#include <map>
#include <iostream>
#include <boost/optional.hpp>
class OrderBook{
    std::map<float,int> bids,asks;

    void add(int ammount, float price, bool isBid);
public:
    struct BidAsk{
        typedef boost::optional<std::pair<float,int>> Entry;
        Entry bid, ask;
        boost::optional<int>spread() const;
    };

    bool isEmpty();
    void addBid(int ammount, float price);
    void addAsk(int ammount, float price);

    BidAsk getBidAsk();

};