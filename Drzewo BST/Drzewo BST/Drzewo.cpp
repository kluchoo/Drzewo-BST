#include "Drzewo.h"
#include <iostream>

Drzewo::Drzewo() : korzen(nullptr), iloscElementow{} {};

void Drzewo::dodajElement(int wartosc) {

	elementDrzewa* nowyElement = new elementDrzewa;
	nowyElement->wartosc = wartosc;
	nowyElement->lewy = nullptr;
	nowyElement->prawy = nullptr;


	if (korzen == nullptr) {
		korzen = nowyElement;
		iloscElementow++;
	}
	else {
		elementDrzewa* sciezka = korzen;
		while (true) {
			if (nowyElement->wartosc > sciezka->wartosc) {
				if (sciezka->prawy != nullptr) {
					sciezka = sciezka->prawy;
				}
				else {
					sciezka->prawy = nowyElement;
					iloscElementow++;
					return;
				}
			}
			else {
				if (sciezka->lewy != nullptr) {
					sciezka = sciezka->lewy;
				}
				else {
					sciezka->lewy = nowyElement;
					iloscElementow++;
					return;
				}
			}
		}
	}

};
void Drzewo::usunElement(int wartosc) {};
void Drzewo::usunDrzewo() {};
elementDrzewa* Drzewo::szukajElementu(int wartosc) {
	elementDrzewa* temp = nullptr;
	return temp;
};
void Drzewo::wyswietlDrzewo() {};
void Drzewo::zapiszDoPliku() {};
void Drzewo::wczytajZPliku() {};

