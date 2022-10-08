#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

void zadanie1()
{
    bool first = false;
    string liczba;
    int ilosc = 0;

    fstream plik;
    plik.open("przyklad.txt", ios::in);
    if (plik.good() == false) cout << "Błąd przy otwieraniu pliku";
    string linia;
    

    while (getline(plik, linia)) {
        if (linia[0] == linia[linia.length() - 1]) {
            if (!first) {
                first = true;
                liczba = linia;
            }
            ilosc++;
        }
    }
    plik.close();

    cout << liczba << " " << ilosc << endl;
}

void zadanie2()
{
    int pom, pomi;
    int liczba;
    bool koniec;
    int x, y;
    int maks = 0, maksy = 0;
    int wynik, wyniky;
    fstream plik;
    plik.open("przyklad.txt", ios::in);
    if (plik.good() == false) cout << "Błąd przy otwieraniu pliku";
    string linia;


    while (getline(plik, linia)) {
        liczba = stoi(linia);
        koniec = false;
        x = 0;
        y = 0;
        pom = liczba;
        pomi = 0;
        for (int i = 2; i <= pom/2; i++)
        {
            if (pom % i == 0) {
                pom /= i;
                
                if (i != pomi) {
                    y++;
                }
                x++;
                pomi = i;
                i--;
            }
            
        }
        if (x > maks) {
            maks = x+1;
            wynik = liczba;
        }
        if (y > maksy) {
            maksy = y + 1;
            wyniky = liczba;
        }
        
    }
    cout << wynik << " " << maks << " " << wyniky << " " << maksy << endl;
    plik.close();

}

void zad3() {

    bool first = false;
    int liczba1 = 0, liczba2, liczba3;
    int ilosc = 0, w = 0, w5 = 0;;

    fstream plik;
    plik.open("przyklad.txt", ios::in);
    if (plik.good() == false) cout << "Błąd przy otwieraniu pliku";
    string linia, linia2;

    fstream trojki;
    trojki.open("trojki.txt", ios::out | ios::app);

    int tablica[200];
    int i = 0;

    while (getline(plik, linia)) 
    {
        tablica[i] = stoi(linia);
        i++;
    }
    
    for (int j = 0; j < 200; j++)
    {
        for (int y = 0; y < 200; y++)
        {
            if (tablica[j] != tablica[y] && tablica[y] % tablica[j] == 0)
            {
                for (int x = 0; x < 200; x++)
                {
                    if (tablica[x] % tablica[y] == 0 && tablica[x] != tablica[y])  {
                        w++;
                        if (trojki.good() == true)
                        {
                            trojki <<tablica[j] << " " << tablica[y] << " " << tablica[x] << endl;
                        }
                        for (int z = 0; z < 200; z++)
                        {
                            if (tablica[z] % tablica[x] == 0 && tablica[z] != tablica[x]) 
                            {
                                for (int p = 0; p < 200; p++)
                                {
                                    if (tablica[p] % tablica[z] == 0 && tablica[z] != tablica[p]) {
                                        w5++;
                                    }
                                }
                            }
                            
                        }
                    }

                }
            }
            
        }
    }
    trojki.close();
    plik.close();

    cout << w <<" "<< w5 << endl;
}

int main()
{
    zadanie1();
    zadanie2();
    zad3();
    
 }

