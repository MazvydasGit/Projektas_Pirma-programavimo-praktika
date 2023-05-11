#include "Maistukas.h"

Maistukas::Maistukas()
{
    spawn_food();
}

void Maistukas::spawn_food()
{
    vieta.X = rand() % (PLOTIS-3)+1;
    vieta.Y = rand() % (AUKSTIS-3)+1;
}

COORD Maistukas::gauti_maisto_vieta() {return vieta;}