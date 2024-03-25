#include <iostream>
#include <string>
#include "defualts.h"
#include "Aktie.h"
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
        return hashtable->searchStock(string_to_upper(tickerSymbol));
    }
    else{
        std::string name;
        cout << "Enter the Name: ";
        cin >> name;
        if(tickerSymbolData[string_to_upper(name)] == ""){return -1;}
        std::string tickerSymbol = tickerSymbolData[string_to_upper(name)];
        return hashtable->searchStock(tickerSymbol);
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
}
void programmMenu(Hashtabelle* hashtable){
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
        default:
            cout << "Invaild Input" << endl;
    }
}
int main()
{
    Hashtabelle* hashtabelle1 = new Hashtabelle();
    while(true) {
        programmMenu(hashtabelle1);
    }
}

