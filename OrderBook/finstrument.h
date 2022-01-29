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
struct Book{
    std::string symbols;
    std::vector<BidAsk> bid;
    std::vector<BidAsk> ask;
};
struct Trade{
    std::string symbols;
    int quantity;
    double price;
};
struct Event{
    Book book; //Book OrderKey
    Trade trade; // Trade OrderKey
};

enum BookTrade{
    _BOOK,
    _TRADE
};

//Is used for money normalized price;
//
//
//
class punct_facet: public std::numpunct<char>
{
    virtual char do_decimal_point() const { return '.'; }
    virtual char do_thousands_sep() const { return ','; }
    virtual std::string do_grouping() const { return "\03"; }
};

class FInstrument{
   
    BookTrade bookTrade;
    punct_facet *facet;
    //Instruments Name (symbol)
    std::string mSymbol;
    std::string mOrderKey;
    
public:
    FInstrument(){
        mSymbol = "";
    }
    FInstrument(const std::string &symbol){
        mSymbol = symbol;
    }

    void printToFile(const std::string &fileName,const std::string &content);


    OrderBook book; //Every Financial Instruments has its own orderbook
    void parseJSONObject(json &js);


    std::string normalizePrice(const double &price);


    void setSymbol(const std::string &symbol){
        mSymbol = symbol;
    }
    std::string getInstrumentName(){
        return mSymbol;
    }

    void setOrderKey(const std::string &key){
        mOrderKey = key;
    }
    std::string getOrderKey(){
        return mOrderKey;
    }
};


#endif