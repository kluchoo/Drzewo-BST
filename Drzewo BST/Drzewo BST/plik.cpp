#include "plik.h"
#include "Drzewo.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

plik::plik()
{
}

plik::~plik()
{
}


void plik::zapiszDoPlikuBinarnego(elementDrzewa* element, std::ofstream& plik) {
    if (element != nullptr) {
        zapiszDoPlikuBinarnego(element->lewy, plik);
        plik.write(reinterpret_cast<char*>(&element->wartosc), sizeof(element->wartosc));
        zapiszDoPlikuBinarnego(element->prawy, plik);
    }
};
void plik::wczytajZPliku(std::string sciezka, Drzewo& drzewo) {
    std::fstream plik(sciezka, std::ios::in);

    if (!plik) {
        cout << "plik nie istnieje!";
        return;
    }

    do{
        int a;
        plik >> a;
        if(!plik.eof()) drzewo.dodajElement(a);
    } while (plik);
};
