//
// Created by Muayad Mhanna on 25.03.24.
//

#ifndef STOCKSAPP_HASHTABELLE_H
#define STOCKSAPP_HASHTABELLE_H


#include "defualts.h"
#include "Aktie.h"
#include <string>


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
    Aktie* searchStock(std::string name);


protected:

private:
    // Hashtabelle von Aktien pointers
    Aktie* StocksHashtable[HASHTABLE_SIZE];
    int numberOfInsertions;

};


#endif //STOCKSAPP_HASHTABELLE_H
