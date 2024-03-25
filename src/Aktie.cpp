#include "Aktie.h"

Aktie::Aktie()
{
    //ctor
}

Aktie::~Aktie()
{
    //dtor
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
