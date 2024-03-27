//
// Created by Muayad Mhanna on 25.03.24.
//
// /Users/muayad/Downloads/MSFT(3).csv
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
            cout << "Stock has been added" << endl;
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

void Hashtabelle::importStock(int index,ifstream file) {
    int counter = 0;
    string line;
    while(getline(file,line) && counter <= 30){
        KursDaten* kursData = new KursDaten();
        if(counter == 0) {
            counter++;
            continue;
        }
        string cell;
        int cnt = 0;
        for (char c: line += ",") {
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
}
bool Hashtabelle::stockDataEntries(int index) {
    return StocksHashtable[index]->StockData[0] != nullptr;
}
void Hashtabelle::searchStock(int index) {
    if(stockDataEntries(index)){
        Aktie* aktie = StocksHashtable[index];
        int dateIndex = aktie->latestDateGetter();
        KursDaten* kursdata = aktie->StockData[dateIndex];
        cout << "Name: " << aktie->nameGetter() << endl;
        cout << "WKN: " << aktie->wknGetter() << endl;
        cout << "Ticker Symbol: " << aktie->tickerSymbolGetter() << endl;
        cout << "StockPrices for: " << kursdata->date <<endl;
        cout << "Open: " << kursdata->open << endl;
        cout << "High: " << kursdata->high << endl;
        cout << "Low: " << kursdata->low << endl;
        cout << "Close: " << kursdata->close << endl;
        cout << "Adj.Close: " << kursdata->adjClose << endl;
        cout << "Volume: " << kursdata->volume << endl;
    }
    else{cout << "No Stockprices has been imported" << endl;}
}
void Hashtabelle::plotStock(int index) {
    if(stockDataEntries(index)){
        StocksHashtable[index]->graphPrinter();
    }
    else{cout << "No Stockprices has been imported" << endl;}

}
void Hashtabelle::saveHashtable() {
    std::string path;
    cout << "Please enter the Path: " ;
    cin >> path;
    std::string fileName;
    cout << "Please enter the file name: ";
    cin >> fileName;
    ofstream file(path + fileName + ".csv");
    if (!file.is_open()) {
       cout << "Error creating file!" << endl;
    }
    for(int i = 0; i < HASHTABLE_SIZE; i++){
        if(StocksHashtable[i] != nullptr) {
            Aktie *aktie = StocksHashtable[i];
            file << aktie->nameGetter() + ",";
            file << aktie->wknGetter() + ",";
            file << aktie->tickerSymbolGetter() + ",\n";
            file << "s\n";
            for(int x = 0; x < STOCK_DATA_SIZE; x++){
                if(aktie->StockData[x] != nullptr){
                    KursDaten* kursdata = aktie->StockData[x];
                    file << kursdata->date + ",";
                    file << kursdata->open + ",";
                    file << kursdata->high + ",";
                    file << kursdata->low + ",";
                    file << kursdata->close + ",";
                    file << kursdata->volume + ",";
                    file << kursdata->adjClose + ",\n";
                }
            }
            file <<"e\n";
        }
    }
    file.close();
}
void Hashtabelle::loadHashtable() {
    cout << "Please enter the path of csv file: ";
    std::string path;
    cin >> path;
    ifstream file(path);
    if (!file.is_open()) {
        cout << "Error by opening file" << endl;
        return;
    }
    string line;
    bool checker = true;
    std::string name;
    std::string wkn;
    std::string tickerSymbol;
    int counter = 0;
    while (getline(file, line)) {
        string cell;
        if (line == "s") {
            checker = false;
            continue;
        }
        if (line == "e") {
            checker = true;
            counter = 0;
            continue;
        }
        if (checker) {
            int cnt = 0;
            for (char c: line) {
                if (c != ',') {
                    cell += c;
                } else {
                    switch (cnt) {
                        case 0:
                            name = cell;
                            break;
                        case 1:
                            wkn = cell;
                            break;
                    }
                    cnt++;
                    cell.clear();
                }
            }
            addStock(name, wkn);
        } else {
            tickerSymbol = tickerSymbolGetter(name);
            int index = searchStockIndex(tickerSymbol);
            KursDaten* kursData = new KursDaten();
            int cnt = 0;
            for (char c: line += ",") {
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
            delete StocksHashtable[index]->StockData[counter];
            StocksHashtable[index]->StockData[counter] = nullptr;
            StocksHashtable[index]->StockData[counter] = kursData;
            counter++;
        }
    }
    file.close();
    cout << "The Hashtable has been loaded" << endl;
}