//
// Created by Muayad Mhanna on 25.03.24.
//

#ifndef STOCKSAPP_KURSDATEN_H
#define STOCKSAPP_KURSDATEN_H

#include <iostream>


class KursDaten
{
public:
    KursDaten();
    virtual ~KursDaten();
    std::string date;
    std::string open;
    std::string high;
    std::string low;
    std::string close;
    std::string adjClose;
    std::string volume;

protected:

private:
};



#endif //STOCKSAPP_KURSDATEN_H
