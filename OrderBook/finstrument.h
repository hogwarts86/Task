#ifndef FINSTRUMENT_H
#define FINSTRUMENT_H

#include <iostream>
#include "orderbook.h"
using namespace std;

class FInstrument{

    //Instruments Name
    std::string iName;

public:
    FInstrument(string name);
    std::string getInstrumentName();
    OrderBook book;

};


#endif