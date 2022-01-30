#include "finstrument.h"
#include <chrono>

#define OUTPUTFILEPATH "../Output/"
void FInstrument::printToFile(const std::string &fileName, const std::string &content){
    if(!std::fstream(fileName))
        std::cout << "Creating "<<fileName<<std::endl;
    std::fstream file(fileName,std::ios::out|std::ios::app);

    if(file.is_open())
    {
        file << content; //content to be written
    }
    else
        std::cout<<"File:"<<fileName<<" can't opened and created"<<std::endl;
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
    // std::cout<<"This is on parseJSONObject on :"<<mSymbol<<std::endl;
    auto startTime(std::chrono::high_resolution_clock::now());
    std::string sTransaction = js.begin().key();
    if(sTransaction == "book")
        bookTrade = _BOOK;
    else if(sTransaction == "trade")
        bookTrade = _TRADE;
    else{
        std::cout<<"Can't process transaction";
    }

    auto print = [&](std::string text, int ammount, double price){
            std::string sPrice = normalizePrice(price);
            std::stringstream ss;
            ss<<text<<ammount<<" @ "<<sPrice<<std::endl;
            // std::cout<<"Message:"<<ss.str();
            std::string sPath(OUTPUTFILEPATH);
            std::string fileName = sPath + mSymbol +".txt";
            printToFile(fileName,ss.str());
    };
    switch(bookTrade){
        case _BOOK:{

        //Check bid Case
            if(!js["book"]["bid"].empty()){
                for(auto &array : js["book"]["bid"]){
                    book.addBid(array["quantity"],array["price"]);
                    //Print Here
                    double dPrice = array["price"];
                    int ammount = array["quantity"];
                    std::string textToPrint = "PASSIVE BUY ";
                    print(textToPrint,ammount,dPrice);
                    
                }
            }

            //Check ask Case and add it to orderbook if any
            if(!js["book"]["ask"].empty()){
                for(auto &array : js["book"]["ask"]){
                    book.addAsk(array["quantity"],array["price"]);
                    //Print Here
                    double dPrice = array["price"];
                    int ammount = array["quantity"];
                    std::string textToPrint = "PASSIVE SELL ";
                    print(textToPrint,ammount,dPrice);
                    
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
                std::string textToPrint = "AGGRESIVE SELL ";
                print(textToPrint,ammount,price);
            }
            else{
                book.removeAsk(ammount,price);
                //Print Here
                std::string textToPrint = "AGGRESIVE BUY ";
                print(textToPrint,ammount,price);
            }

        }
        break;/* END of Trade Case**/
        default:{

        }
    };
    auto endTime(std::chrono::high_resolution_clock::now());

    std::cout<<"Duration for parse of event in "<<mSymbol<<" is "
    << std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count()
    << " ms"<<std::endl;
}


std::string FInstrument::normalizePrice(const double &price){
    std::stringstream stream;
    stream.imbue(std::locale(stream.getloc(),new punct_facet));
    stream << std::fixed << std::setprecision(2) << price;
    return stream.str();
}
