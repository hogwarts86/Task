#include "finstrument.h"


FInstrument::FInstrument(std::string name)
{
    iName = name;
}


std::string FInstrument::getInstrumentName(){
    return iName;
}

void parseJSONObject(json &js, BookOrTrade &bot, std::string bookorder="book"){
    int i = 0;
//     bot.symbols = js[bookorder]["symbol"];
//     bot.bid.resize(js[bookorder]["bid"].size());
//     if(!js[bookorder]["bid"].empty()){
//         for(auto& array : js[bookorder]["bid"]){
//             bot.bid[i].count = array["count"];
//             bot.bid[i].quantity = array["quantity"];
//             bot.bid[i].price = array["price"];
//             i++;
//         };
//     };
//     i=0;
//     bot.ask.resize(js[bookorder]["ask"].size());
//     if(!js[bookorder]["ask"].empty()){
//         for(auto &array : js[bookorder]["ask"]){
            
//             bot.ask[i].count = array["count"];
//             bot.ask[i].quantity = array["quantity"];
//             bot.ask[i].price = array["price"];
//             i++;
//         }
//     }
    
}