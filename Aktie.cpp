//
// Created by Muayad Mhanna on 25.03.24.
//

#include "Aktie.h"

Aktie::Aktie()
{
    for(int  i = 0 ; i < STOCK_DATA_SIZE ; i++){
        StockData[i] = nullptr;
    }
}

Aktie::~Aktie()
{
    for(int  i = 0 ; i < STOCK_DATA_SIZE ; i++){
        delete StockData[i];
        StockData[i] = nullptr;
    }
}
std::string Aktie::nameGetter() const{
    return this->name;
}
std::string Aktie::wknGetter() const{
    return this->wkn;
}
std::string Aktie::tickerSymbolGetter() const{
    return this->tickerSymbol;
}
void Aktie::nameSetter(std::string name){
    this->name = name;
}
void Aktie::wknSetter(std::string wkn){
    this->wkn = wkn;
}
void Aktie::tickerSymbolSetter(std::string tickerSymbol){
    this->tickerSymbol = tickerSymbol;
}
void Aktie::printAllDates() {
    for(int i = 0; i < STOCK_DATA_SIZE; i++){
        cout << StockData[i]->date << endl;
    }
}