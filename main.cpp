#include <iostream>
#include <string>
#include "defualts.h"
#include "Hashtabelle.h"


using namespace std;

void addStock(Hashtabelle* hashtable){
    std::string name;
    std::string confirmName;
    while(true){
        cout << "Please enter the Name: ";
        cin >> name;
        cout << "Please confirm: ";
        cin >> confirmName;
        if(name == confirmName){break;}
    }
    std::string wkn;
    cout << "Please enter the WKN: ";
    cin >> wkn;
    hashtable->addStock(name,wkn);
}

int searchStockIndex(Hashtabelle* hashtable){
    int userInput;
    cout << "Search with TickerSymbol(1) or Name(2): ";
    cin >> userInput;
    if(userInput == 1){
        std::string tickerSymbol;
        cout << "Enter the TickerSymbol: ";
        cin >> tickerSymbol;
        return hashtable->searchStockIndex(string_to_upper(tickerSymbol));
    }
    else{
        std::string name;
        cout << "Enter the Name: ";
        cin >> name;
        if(tickerSymbolData[string_to_upper(name)].empty()){return -1;}
        std::string tickerSymbol = tickerSymbolData[string_to_upper(name)];
        return hashtable->searchStockIndex(tickerSymbol);
    }
}
void deleteStock(Hashtabelle* hashtable){
    int index = searchStockIndex(hashtable);
    if(index == -1){
        cout << "Stock has been not found" << endl;
    }
    else{
        hashtable->deleteStock(index);
        cout << "Stock has been deleted" << endl;
    }
    system("clear");
}
bool fileSize(ifstream& file){
    string line;
    int counter = 0;
    while(getline(file,line)){
        counter ++;
    }
    if(counter < 31){
        cout << "File Should contain 30 StockPrices" << endl;
        return false;
    }
    return true;
}
void importStock(Hashtabelle* hashtable){
    cout << "For which Stock do you want to import the stockprices" << endl;
    int index = searchStockIndex(hashtable);
    if(index == -1){
        cout << "Stock has been not found" << endl;
    }
    else{
        cout << "Please enter the path of csv file: ";
        std::string path;
        cin >> path;
        ifstream file(path);
        if(!file.is_open()){
            cout << "Error by opening file" << endl;
            return;
        }
        if(fileSize(file)) {
            file.clear();
            file.seekg(0, std::ios::beg);
            hashtable->importStock(index, move(file));
            file.close();
        }
    }
    system("clear");
}
void searchStock(Hashtabelle* hashtable){
    int index = searchStockIndex(hashtable);
    if(index == -1){
        cout << "Stock has been not found" << endl;
    }
    else{
        hashtable->searchStock(index);
    }
}
void plotStock(Hashtabelle* hashtable){
    int index = searchStockIndex(hashtable);
    if(index == -1){
        cout << "Stock has been not found" << endl;
    }
    else{
        system("clear");
        hashtable->plotStock(index);
    }
}
bool programmMenu(Hashtabelle* hashtable){
    int userInput;
    while(true){
        cout << "Choose an Option from the menu [ADD (1),DELETE (2), IMPORT(3), SEARCH(4), PLOT(5), SAVE(6), LOAD(7), QUIT(8)]: ";
        cin >> userInput;
        if(userInput >= 1 && userInput <= 8){break;}
    }
    switch (userInput){
        case ADD:
            addStock(hashtable);
            break;
        case DEL:
            deleteStock(hashtable);
            break;
        case IMPORT:
            importStock(hashtable);
            break;
        case SEARCH:
            searchStock(hashtable);
            break;
        case PLOT:
            plotStock(hashtable);
            break;
        case SAVE:
            hashtable->saveHashtable();
            break;
        case LOAD:
            hashtable->loadHashtable();
            break;
        case QUIT:
            return false;
        default:
            cout << "Invaild Input" << endl;
    }
    return true;
}
int main()
{
    Hashtabelle* hashtabelle1 = new Hashtabelle();
    while(true) {
        if(!programmMenu(hashtabelle1)){break;};
    }
    delete hashtabelle1;
}

