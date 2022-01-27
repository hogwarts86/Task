#include "finstrument.h"


FInstrument::FInstrument(string name)
{
    iName = name;
}


std::string FInstrument::getInstrumentName(){
    return iName;
}