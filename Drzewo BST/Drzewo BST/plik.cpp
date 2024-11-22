#include "plik.h"
#include "Drzewo.h"
#include <iostream>
#include <fstream>
using namespace std;

plik::plik()
{
}

plik::~plik()
{
}

void plik::zapiszDoPlikuBinarnego(elementDrzewa* element, const std::string& plik) {
    std::ofstream file(plik, std::ios::binary);

    if (!file) {
        std::cout << "Nie mozna otworzyc pliku do zapisu: " << plik << std::endl;
        return;
    }

    zapiszElementDoPlikuBinarnego(element, file);
    file.close();
}

void plik::zapiszElementDoPlikuBinarnego(elementDrzewa* element, std::ofstream& file) {
    if (element != nullptr) {
        zapiszElementDoPlikuBinarnego(element->lewy, file);
        file.write(reinterpret_cast<char*>(&element->wartosc), sizeof(element->wartosc));
        zapiszElementDoPlikuBinarnego(element->prawy, file);
    }
}

void plik::wczytajZPliku(std::string sciezka, Drzewo& drzewo) {
    std::fstream plik(sciezka, std::ios::in);

    if (!plik) {
        cout << "Plik nie istnieje!";
        return;
    }

    do {
        int a;
        plik >> a;
        if (!plik.eof()) drzewo.dodajElement(a);
    } while (plik);
}