#include "Gyvaciokas.h"

Gyvaciokas::Gyvaciokas(COORD vieta, int greitis)
{
    this->vieta = vieta;
    this->greitis = greitis;
    ilgis = 1;
    kryp = 'n';

    kunas.push_back(vieta);
}

vector<COORD> Gyvaciokas::gauti_kuna() {return kunas;}

void Gyvaciokas::keisti_krypti(char kryptis)
{
    kryp = kryptis;
}
void Gyvaciokas::pajudinti_gyvacioka()
{
    switch(kryp)
    {
        case 'u': vieta.Y -= greitis; break;
        case 'd': vieta.Y += greitis; break;
        case 'l': vieta.X -= greitis; break;
        case 'r': vieta.X += greitis; break;
    }

    kunas.push_back(vieta);
    if(kunas.size() > ilgis) kunas.erase(kunas.begin());
}

COORD Gyvaciokas::gauti_vieta() {return vieta;}

bool Gyvaciokas::valgom(COORD gauti_maisto_vieta)
{
    if (gauti_maisto_vieta.X == vieta.X && gauti_maisto_vieta.Y == vieta.Y) return true;
    else return false;
}

void Gyvaciokas::auga()
{
    ilgis++;
}

bool Gyvaciokas::atsitrenke()
{
    if(vieta.X < 1 || vieta.X > PLOTIS-2 || vieta.Y < 1 || vieta.Y > AUKSTIS-2) return true;
    
    for(int i = 0; i < ilgis-1; i++)
    {
        if(vieta.X == kunas[i].X && vieta.Y == kunas[i].Y) return true;
    }
    return false;

}