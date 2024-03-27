//
// Created by Muayad Mhanna on 25.03.24.
//

#ifndef STOCKSAPP_HASHTABELLE_H
#define STOCKSAPP_HASHTABELLE_H


#include <iostream>
#include "defualts.h"
#include "Aktie.h"
#include <string>
#include <fstream>


class Hashtabelle
{
public:
    Hashtabelle();
    virtual ~Hashtabelle();
    // Erstellt ein eindeutiges Kürzel für die Aktie
    std::string tickerSymbolGetter(std::string name);
    // Fügt die Aktie in der HashTabelle hin
    void addStock(std::string name, std::string wkn);
    // um das Index in der StocksHashtable zu kriegen
    int hashFunction(std::string tickerSymbol);
    int searchStockIndex(std::string name);
    void deleteStock(int index);
    void importStock(int index);
    void searchStock(int index);


protected:

private:
    // Hashtabelle von Aktien pointers
    Aktie* StocksHashtable[HASHTABLE_SIZE];
    int numberOfInsertions;

};


#endif //STOCKSAPP_HASHTABELLE_H
