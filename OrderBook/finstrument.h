#ifndef FINSTRUMENT_H
#define FINSTRUMENT_H

#include <iostream>
#include <vector>
#include "orderbook.h"
#include <json.hpp>


using json = nlohmann::json;
struct BidAsk{
    int count;
    int quantity;
    double price;
};
struct BookOrTrade{
    std::string symbols;
    std::vector<BidAsk> bid;
    std::vector<BidAsk> ask;
};
struct Event{
    BookOrTrade bookOrTrade;
};

class FInstrument{

    //Instruments Name
    std::string iName;
    json m_JSON;
public:
    FInstrument(){
        iName = "";
    }

    FInstrument(std::string name);
    std::string getInstrumentName();
    OrderBook book; //Every Financial Instruments has its own orderbook
    void parseJSONObject(json &js, BookOrTrade & bot, std::string bookorder);
};


#endif