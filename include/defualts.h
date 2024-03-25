//****************************************************************************
//                                                                           *
// Die Größe der Hashtabelle wurde auf 997 gesetzt, da 997 eine Primzahl ist *
// und somit Kollisionen beim Hinzufügen in der Hashtabelle vermieden werden.*
//                                                                           *
//****************************************************************************
#ifndef DEFAULTS_H
#define DEFAULTS_H
#define HASHTABLE_SIZE 997
#define STOCK_DATA_SIZE 30
#include <string>
#include <iostream>
#include <unordered_map>
#pragma once

using namespace std;

std::string string_to_upper(std::string name);


extern unordered_map <string,string> tickerSymbolData;
#endif // DEFAULTS_H


