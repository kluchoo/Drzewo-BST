#include "plik.h"
#include "Drzewo.h"
#include <iostream>
#include <fstream>
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
 * @param element Wskaznik na korzen drzewa.
 * @param plik sciezka do pliku, w ktorym ma zostac zapisane drzewo.
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
 * @param element Wskaznik na element drzewa.
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
 * @param sciezka sciezka do pliku, z ktorego ma zostac wczytane drzewo.
 * @param drzewo Referencja do obiektu drzewa, do ktorego maja zostac dodane elementy.
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
