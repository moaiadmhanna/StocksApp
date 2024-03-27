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

void Aktie::graphPrinter() {
        int max = 0;
        for(int i = 0; i < STOCK_DATA_SIZE; i++){
            if(stoi(StockData[i]->close)%100 > max){max = stoi(StockData[i]->close)%100;}
        }
        cout << "CLOSED" << endl;
        cout << "^" << endl;
        for(int y = max ; y > 0 ; y--){
            cout << "|";
            for(int x = 0 ; x < STOCK_DATA_SIZE ; x++){
                if(stoi(StockData[x]->close)%100 >= y){
                    cout << "* ";
                }
                else{
                    cout << "  ";
                }
            }
            cout<<endl;
        }
        for(int i = 0; i < STOCK_DATA_SIZE*2; i++){
            cout << "-";
        }
        cout<<">"<<endl;
        for(int i = 0; i < STOCK_DATA_SIZE*2; i++){
            cout << " ";
        }
        cout << "Days" << endl;
}