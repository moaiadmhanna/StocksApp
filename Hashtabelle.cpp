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
    for(int i = 0 ; i < HASHTABLE_SIZE ; i++){
        delete StocksHashtable[i];
        StocksHashtable[i] = nullptr;
    }
}



std::string Hashtabelle::tickerSymbolGetter(std::string name){

    // Wenn das Kürzel in KürzelMapData ist

    if(tickerSymbolData[string_to_upper(name)] != ""){return tickerSymbolData[string_to_upper(name)];};

    // Algo für das manuelle Kürzel

    int nameLength = name.length();
    std::string tickerSymbol;
    tickerSymbol += toupper(name[0]);
    for(int i = 1 ; i < nameLength ; i++){
        if (i % 2 == 0)
            tickerSymbol += toupper(name[i]);

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
        // Damit die Aktie nur einmal in der Hashtabelle gespeichert wird.
        else if (StocksHashtable[index]->nameGetter() == name){
            cout << "Stock has been already added" << endl;
            break;
        }
        counter++;
    }
}
// TO_DO das müssen wir noch erweitern
int Hashtabelle::searchStockIndex(std::string tickerSymbol){
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
    numberOfInsertions--;
}

void Hashtabelle::importStock(int index) {
    cout << "Please enter the path of csv file: ";
    std::string path;
    cin >> path;
    ifstream file(path);
    if(!file.is_open()){
        cout << "Error by opening file" << endl;
        return;
    }
    string line;
    int counter = 0;
    while(getline(file,line) && counter <= 30){
        KursDaten* kursData = new KursDaten();
        if(counter == 0) {
            counter++;
            continue;
        }
        string cell;
        int cnt = 0;
        for (char c: line) {
            if (c != ',') {
                cell += c;
            } else {
                switch (cnt) {
                    case 0:
                        kursData->date = cell;
                        break;
                    case 1:
                        kursData->open = cell;
                        break;
                    case 2:
                        kursData->high = cell;
                        break;
                    case 3:
                        kursData->low = cell;
                        break;
                    case 4:
                        kursData->close = cell;
                        break;
                    case 5:
                        kursData->adjClose = cell;
                        break;
                    case 6:
                        kursData->volume = cell;
                        break;
                }
                cnt++;
                cell.clear();
            }
        }
        delete StocksHashtable[index]->StockData[counter-1];
        StocksHashtable[index]->StockData[counter-1] = nullptr;
        StocksHashtable[index]->StockData[counter-1] = kursData;
        counter++;
    }
    // Close the file
    file.close();
}
void Hashtabelle::searchStock(int index) {

}