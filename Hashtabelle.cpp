//
// Created by Muayad Mhanna on 25.03.24.
//

#include "Hashtabelle.h"

Hashtabelle::Hashtabelle()
{
    numberOfInsertions = 0;
    for(int i = 0 ; i < HASHTABLE_SIZE; i++){
        StocksHashtable[i] = nullptr;
    }
}

Hashtabelle::~Hashtabelle()
{
    //dtor
}



std::string Hashtabelle::tickerSymbolGetter(std::string name){

    // Wenn das Kürzel in KürzelMapData ist

    if(tickerSymbolData[string_to_upper(name)] != ""){return tickerSymbolData[string_to_upper(name)];};

    // Algo für das manuelle Kürzel

    int nameLength = name.length();
    std::string tickerSymbol;
    tickerSymbol += toupper(name[0]);
    for(int i = 1 ; i < nameLength ; i++){
        if(i%2 == 0){
            tickerSymbol += toupper(name[i]);
        }
    }
    tickerSymbolData[string_to_upper(name)] = tickerSymbol;
    return tickerSymbol;

}

int Hashtabelle::hashFunction(std::string tickerSymbol){
    int value = 0;
    for(int i = tickerSymbol.length() ; i > 0 ; i--){
        value += tickerSymbol[tickerSymbol.length()-i]*(HASHTABLE_SIZE/i);
    }
    value = value%HASHTABLE_SIZE;
    return value;
}

void Hashtabelle::addStock(std::string name, std::string wkn){
    if(numberOfInsertions >= HASHTABLE_SIZE){
        cout << "HASHTABLE IS FULL" << endl;
        return;
    }
    std::string tickerSymbol = tickerSymbolGetter(name);
    Aktie* aktie1 = new Aktie();
    aktie1->nameSetter(name);
    aktie1->wknSetter(wkn);
    aktie1->tickerSymbolSetter(tickerSymbol);
    int counter = 0;
    int index = 0;
    while(true){
        index = (hashFunction(tickerSymbol) + (counter*counter))%HASHTABLE_SIZE;
        if(StocksHashtable[index] == nullptr){
            StocksHashtable[index] = aktie1;
            numberOfInsertions++;
            break;
        }
        counter++;
    }
}
// TO_DO das müssen wir noch erweitern
int Hashtabelle::searchStock(std::string tickerSymbol){
    int index = -1;
    int counter = 0;
    while(true){
        index = (hashFunction(tickerSymbol) + (counter*counter))%HASHTABLE_SIZE;
        if(StocksHashtable[index] == nullptr){
            index = -1;
            break;
        }
        if(StocksHashtable[index]->tickerSymbolGetter() == tickerSymbol){break;}
        counter++;
    }
    return index;
}
void Hashtabelle::deleteStock(int index) {
    delete StocksHashtable[index];
    StocksHashtable[index] = nullptr;
}