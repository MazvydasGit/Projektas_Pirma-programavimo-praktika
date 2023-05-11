#include <iostream>
#include <windows.h>
#include <vector>

using namespace std;

#define PLOTIS 50
#define AUKSTIS 25

class Gyvaciokas
{
private:
    COORD vieta;
    int ilgis;
    int greitis;
    char kryp;
    vector<COORD> kunas;
public:
    Gyvaciokas(COORD vieta, int greitis);
    void keisti_krypti(char kryptis);
    void pajudinti_gyvacioka();
    COORD gauti_vieta();

    vector<COORD> gauti_kuna();

    bool valgom(COORD gauti_maisto_vieta);

    void auga();
    bool atsitrenke();

};

