cmake_minimum_required(VERSION 3.27)
project(StocksApp)

set(CMAKE_CXX_STANDARD 17)

add_executable(StocksApp main.cpp
        Aktie.h
        KursDaten.cpp
        Hashtabelle.cpp
        defualts.cpp
        Aktie.cpp)
