#include "plik.h"
#include "Drzewo.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/**
 * @brief Konstruktor klasy plik.
 */
plik::plik()
{
}

/**
 * @brief Destruktor klasy plik.
 */
plik::~plik()
{
}

/**
 * @brief Zapisuje drzewo do pliku w formacie binarnym.
 *
 * @param element Wska�nik na korze� drzewa.
 * @param plik �cie�ka do pliku, w kt�rym ma zosta� zapisane drzewo.
 */
void plik::zapiszDoPlikuBinarnego(elementDrzewa* element, const std::string& plik) {
    std::ofstream file(plik, std::ios::binary);

    if (!file) {
        std::cout << "Nie mozna otworzyc pliku do zapisu: " << plik << std::endl;
        return;
    }

    zapiszElementDoPlikuBinarnego(element, file);
    file.close();
}

/**
 * @brief Rekurencyjnie zapisuje elementy drzewa do pliku w formacie binarnym.
 *
 * @param element Wska�nik na element drzewa.
 * @param file Referencja do strumienia pliku.
 */
void plik::zapiszElementDoPlikuBinarnego(elementDrzewa* element, std::ofstream& file) {
    if (element != nullptr) {
        zapiszElementDoPlikuBinarnego(element->lewy, file);
        file.write(reinterpret_cast<char*>(&element->wartosc), sizeof(element->wartosc));
        zapiszElementDoPlikuBinarnego(element->prawy, file);
    }
}

/**
 * @brief Wczytuje drzewo z pliku tekstowego.
 *
 * @param sciezka �cie�ka do pliku, z kt�rego ma zosta� wczytane drzewo.
 * @param drzewo Referencja do obiektu drzewa, do kt�rego maj� zosta� dodane elementy.
 */
void plik::wczytajZPliku(std::string sciezka, Drzewo& drzewo) {
    std::fstream plik(sciezka, std::ios::in);

    if (!plik) {
        cout << "plik nie istnieje!";
        return;
    }

    do {
        int a;
        plik >> a;
        if (!plik.eof()) drzewo.dodajElement(a);
    } while (plik);
}