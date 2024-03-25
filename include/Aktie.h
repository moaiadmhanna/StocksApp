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
        void nameGetter() const;
        void wknGetter() const;
        void tickerSymbolGetter() const;
        std::string nameSetter(std::string name);
        std::string wknSetter(std::string wkn);

    protected:

    private:
        // name von der Aktie
        std::string name;
        // Wertpapierkennnummer von der Aktie
        std::string WKN;
        // Kürzel von der Aktie
        std::string tickerSymbol;
        // KurseDaten von der Aktie
        KursDaten* StockData[STOCK_DATA_SIZE];

};

#endif // AKTIE_H
