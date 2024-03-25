#ifndef HASHTABELLE_H
#define HASHTABELLE_H
#include "defualts.h"
#include "Aktie.h"
#include <string>


class Hashtabelle
{
    public:
        Hashtabelle();
        virtual ~Hashtabelle();
        // Erstellt ein eindeutiges K�rzel f�r die Aktie
        std::string tickerSymbolGetter(std::string name);
        // F�gt die Aktie in der HashTabelle hin
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

#endif // HASHTABELLE_H
