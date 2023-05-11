#include <iostream>
#include <windows.h>
#include <ctime>

#include "Gyvaciokas.h"
#include "Maistukas.h"

#include <conio.h>  
using namespace std;

#define PLOTIS 50
#define AUKSTIS 25

Gyvaciokas gyvaciokas({PLOTIS/2, AUKSTIS/2}, 1);
Maistukas maistukas;

int taskai = 0;

void gameMap() 
{

    cout << "Surinkti taskai: " << taskai << '\n';

    COORD gyvacioko_vieta = gyvaciokas.gauti_vieta();
    COORD gauti_maisto_vieta = maistukas.gauti_maisto_vieta();

    vector<COORD> gyvacioko_kunas = gyvaciokas.gauti_kuna();

    for(int i = 0; i < AUKSTIS; i++)
    {
        cout << "\t\t#";
        for(int j = 0; j < PLOTIS - 2; j++)
        {
            if(i == 0 || i == AUKSTIS-1 ) cout<<'#';
            else if(i == gyvacioko_vieta.Y && j+1 == gyvacioko_vieta.X) cout << '0';
            else if(i == gauti_maisto_vieta.Y && j+1 == gauti_maisto_vieta.X) cout<< 'x';
            else 
            {
                bool kunoDalis = false;
                for(int k = 0; k < gyvacioko_kunas.size() - 1; k++)
                {
                    if(i == gyvacioko_kunas[k].Y && j+1 == gyvacioko_kunas[k].X)
                    {
                        cout << 'o';
                        kunoDalis = true;
                        break;
                    }
                }

                if (!kunoDalis) cout << ' ';
            }
        }
        cout << "#\n";
    }
}

int main()
{
    srand(time(NULL));
    bool pabaiga = false;
    while(!pabaiga)
    {
        gameMap();
        
        if(kbhit())
        {
            switch (getch())
            {
                case 'w': gyvaciokas.keisti_krypti('u'); break;
                case 'a': gyvaciokas.keisti_krypti('l'); break;
                case 's': gyvaciokas.keisti_krypti('d'); break;
                case 'd': gyvaciokas.keisti_krypti('r'); break;
            }
        }

        if(gyvaciokas.atsitrenke()) pabaiga = true;
        

        if(gyvaciokas.valgom(maistukas.gauti_maisto_vieta()))
        {
            gyvaciokas.auga();
            maistukas.spawn_food();
            taskai++;
        }

        gyvaciokas.pajudinti_gyvacioka();

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 0});
    }




}
