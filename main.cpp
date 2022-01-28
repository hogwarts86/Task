#include <iostream>
#include <orderbook.h>
#include <finstrument.h>
#include <json.hpp>
#include <fstream>



using json = nlohmann::json;

void fromJSON(const json& js, BookOrTrade & bot, std::string bookorder){
    int i = 0;
    bot.symbols = js[bookorder]["symbol"];
    bot.bid.resize(js[bookorder]["bid"].size());
    if(!js[bookorder]["bid"].empty()){
        for(auto& array : js[bookorder]["bid"]){
            bot.bid[i].count = array["count"];
            bot.bid[i].quantity = array["quantity"];
            bot.bid[i].price = array["price"];
            i++;
        };
    };
    i=0;
    bot.ask.resize(js[bookorder]["ask"].size());
    if(!js[bookorder]["ask"].empty()){
        for(auto &array : js[bookorder]["ask"]){
            
            bot.ask[i].count = array["count"];
            bot.ask[i].quantity = array["quantity"];
            bot.ask[i].price = array["price"];
            i++;
        }
    }
}

int main(int argc, char* argv[]){
    BookOrTrade bot;
    std::cout<<"This is the main program\n";
    std::ifstream input("../Test/test.json");
    json jf;
    input>>jf;
    std::cout<<"JSON OBJECT symbols: "<<jf.at("book").at("symbol") <<std::endl;
    std::string bookOrder = jf.begin().key();
    fromJSON(jf,bot,bookOrder);

    std::cout<<bot.symbols;

    return 0;
}