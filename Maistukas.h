#ifndef MAISTUKAS_H
#define MAISTUKAS_H

#include <windows.h>
#include <cstdlib>

#define PLOTIS 50
#define AUKSTIS 25

class Maistukas
{
    private:
        COORD vieta;
    public:
        Maistukas();
        void spawn_food();
        COORD gauti_maisto_vieta();
};


#endif