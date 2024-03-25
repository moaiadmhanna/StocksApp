#ifndef AKTIE_H
#define AKTIE_H
#include <iostream>
#include "KursDaten.h"
#include "defualts.h"


class Aktie
{
    public:
        Aktie();
        virtual ~Aktie();
        std::string nameGetter() const;
        std::string wknGetter() const;
        std::string tickerSymbolGetter() const;
        void nameSetter(std::string name);
        void wknSetter(std::string wkn);
        void tickerSymbolSetter(std::string tickerSymbol);

    protected:

    private:
        // name von der Aktie
        std::string name;
        // Wertpapierkennnummer von der Aktie
        std::string wkn;
        // Kürzel von der Aktie
        std::string tickerSymbol;
        // KurseDaten von der Aktie
        KursDaten* StockData[STOCK_DATA_SIZE];

};

#endif // AKTIE_H
