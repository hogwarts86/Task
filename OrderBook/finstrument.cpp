#include "finstrument.h"



void FInstrument::printToFile(const std::string &fileName, const std::string &content){
    if(!std::fstream(fileName))
        std::cout << "Cannot open file, file doesn't exist";
    std::fstream file(fileName,std::ios::out|std::ios::app);

    if(file.is_open())
    {
        file << content; //content to be written
    }
    else
        std::cout<<"File can't opened and created";
    file.close();
}

/**
 * @brief Fungsi ini digunakan untuk melihat apakah
 * terjadi trade atau book.
 * Pada saat pemanggilan fungsi, harus dipastikan bahwa
 * Book dan trade udah jelas tinggal mencari berapa bid dan
 * ask. Jika bid kosong dan ask kosong maka jgn print apapun
 * 
 * Jika trade:
 * Cari apakah ada harga yang ditawarkan, jika tidak maka jadi passive buy.
 * @param js 
 */
void FInstrument::parseJSONObject(json &js){

    //Book,Trade udah di cek
    auto print = [&](std::string text, int ammount, double price){


    };
    switch(bookTrade){
        case _BOOK:{

        //Check bid Case
            if(!js["book"]["bid"].empty()){
                for(auto &array : js["book"]["bid"]){
                    book.addBid(array["quantity"],array["price"]);
                    //Print Here

                }
            }

            //Check ask Case and add it to orderbook if any
            if(!js["book"]["ask"].empty()){
                for(auto &array : js["book"]["ask"]){
                    book.addAsk(array["quantity"],array["price"]);
                    //Print Here
                }
            }
            // NO BID or ASK
        }
        break;/* END of Book Case**/

        case _TRADE:{
            // event.trade.symbols = js["trade"]["symbols"];
            // event.trade.quantity = js["trade"]["quantity"];
            // event.trade.price = js["trade"]["price"];
            int ammount = js["trade"]["quantity"];
            double price = js["trade"]["price"];
            if(book.findPriceInBidTable(price))
            {
                book.removeBid(ammount,price);
                //Print Here
            }
            else{
                book.removeAsk(ammount,price);
                //Print Here
            }

        }
        break;/* END of Trade Case**/
        default:{

        }
    };
 
}


std::string FInstrument::normalizePrice(const double &price){
    std::stringstream stream;
    stream.imbue(std::locale(stream.getloc(),new punct_facet));
    stream << std::fixed << std::setprecision(2) << price;
    return stream.str();
}
