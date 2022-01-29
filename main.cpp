#include <iostream>
#include <orderbook.h>
#include <finstrument.h>
#include <json.hpp>
#include <fstream>
#include <string>

#define OUTPUTFILEPATH "../Output/"

using json = nlohmann::json;


// void fromJSON(const json& js, BookOrTrade & bot, std::string bookorder){
//     int i = 0;
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
// }

int main(int argc, char* argv[]){
    double pi = 123142.3100000390;
    std::stringstream stream;
    stream.imbue(std::locale(stream.getloc(),new punct_facet));
    stream << std::fixed << std::setprecision(2) << pi;
    std::string s = stream.str();
    std::cout<<s<<std::endl;

    return 0;
}