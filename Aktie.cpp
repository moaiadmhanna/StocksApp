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

void Aktie::graphPrinter() const {
        int min = stoi(StockData[0]->close);
        for(int i = 0; i < STOCK_DATA_SIZE; i++) {
            if (stoi(StockData[i]->close) < min) { min = stoi(StockData[i]->close); }
        }
        min-=5;
        int max = 0;
        for(int i = 0; i < STOCK_DATA_SIZE; i++){
            if(stoi(StockData[i]->close) > max){max = stoi(StockData[i]->close);}
        }
        max+=5;
        cout << endl;
        cout << "CLOSED" << endl;
        cout << "^" << endl;
        for(int y = max ; y > min ; y--){
            cout << "| ";
            for(int x = 0 ; x < STOCK_DATA_SIZE ; x++){
                if(stoi(StockData[x]->close) >= y){
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
        cout<<"->"<<endl;
        for(int i = 0; i < STOCK_DATA_SIZE*2; i++){
            cout << " ";
        }
        cout << "Days" << endl;
        cout << endl;
}

int Aktie::latestDateGetter() {
    std::string date = StockData[0]->date;
    int index = 0;
    for(int i = 1; i < STOCK_DATA_SIZE; i++){
        if(StockData[i]->date > date){
            index = i;
            date = StockData[i]->date;
        }
    }
    return index;
}