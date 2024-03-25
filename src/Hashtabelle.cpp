#include "Hashtabelle.h"

Hashtabelle::Hashtabelle()
{
    //ctor
}

Hashtabelle::~Hashtabelle()
{
    //dtor
}

std::string Hashtabelle::tickerSymbolGetter(std::string name){
    int nameLength = name.length();
    int tickerSymbolLength = (nameLength/2) + 1;
    std::string tickerSymbol;
    tickerSymbol += toupper(name[0]);
    //letterCounter wird inkrementieret, bis es gleich tickerSymbolLength ist
    int letterCounter = 1;
    // Counter um durch  name zu laufen
    int counter = 1;
    while(true){
        if(letterCounter == tickerSymbolLength){break;}
        if(counter%2 == 0){

        }
    }

}
void Hashtabelle::addStock(std::string name, std::string wkn){

}
