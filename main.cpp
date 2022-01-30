#include <iostream>
#include <json.hpp>
#include <fstream>

#include <finstrument.h>


using json = nlohmann::json;


int main(int argc, char* argv[]){
    std::map<std::string,FInstrument *> fInstruments;
    std::string fileName("../input.json");
    json jf;
    std::string line;

    std::ifstream fileReader(fileName);
    if(!fileReader.is_open()){
        std::cerr << "Could not open the file - '"<< fileName << "'" << std::endl;
        return EXIT_FAILURE;
    }

    while(getline(fileReader,line)){
        std::stringstream ss(std::ios::out|std::ios::in);
        ss<<line; //
        ss>>jf; //parse to nlohmann json;
        std::string transaction = jf.begin().key();
        std::string symbol = jf[transaction]["symbol"];

        auto it = fInstruments.find(symbol);
        if(it != fInstruments.end()){
            // std::cout <<"Found "<<symbol<<std::endl;
            it->second->parseJSONObject(jf);
        }
        else{
            // std::cout <<"Inserting "<<symbol<<std::endl;
            fInstruments.insert(std::make_pair(symbol,new FInstrument(symbol)));
        }
                

    }




    return 0;
}
