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
    Event event;
    //Book,Trade udah di cek
    
    switch(bookTrade){
        case _BOOK:{

        //Check bid Case
            if(!js["book"]["bid"].empty()){
                int bid_size = js["book"]["bid"].size();
                //Resize container
                event.book.bid.resize(bid_size);
                int i=0;
                for(auto &array : js["book"]["bid"]){
                    event.book.bid[i].count = array["count"];
                    event.book.bid[i].quantity = array["quantity"];
                    event.book.bid[i].price = array["price"];
                    i++;
                }
            }

            //Check ask Case
            if(!js["book"]["ask"].empty()){
                int ask_size = js["book"]["ask"].size();
                //Resize container
                event.book.ask.resize(ask_size);
                int i = 0;
                for(auto &array : js["book"]["ask"]){
                    event.book.ask[i].count = array["count"];
                    event.book.ask[i].quantity = array["quantity"];
                    event.book.ask[i].price = array["price"];
                    i++;
                }
            }
            // NO BID or ASK
        }
        break;/* END of Book Case**/

        case _TRADE:{
            event.trade.symbols = js["trade"]["symbols"];
            event.trade.quantity = js["trade"]["quantity"];
            event.trade.price = js["trade"]["price"];

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
