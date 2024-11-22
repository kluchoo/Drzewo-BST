#include "plik.h"
#include "Drzewo.h"
#include <iostream>
#include <fstream>


void plik::zapiszDoPlikuBinarnego(elementDrzewa* element, std::ofstream& plik) {
    if (element != nullptr) {
        zapiszDoPlikuBinarnego(element->lewy, plik);
        plik.write(reinterpret_cast<char*>(&element->wartosc), sizeof(element->wartosc));
        zapiszDoPlikuBinarnego(element->prawy, plik);
    }
};
void plik::wczytajZPliku() {

};
