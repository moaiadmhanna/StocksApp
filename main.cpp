#include <iostream>
#include <string>
#include "defualts.h"
#include "Aktie.h"
#include "Hashtabelle.h"


using namespace std;

int main()
{
    Hashtabelle* Hashtabelle1 = new Hashtabelle();
    Hashtabelle1->addStock("Microsoft","87654321");
    Aktie* aktie1 = Hashtabelle1->searchStock("MSFT");
    cout << aktie1->nameGetter() << endl;
}

