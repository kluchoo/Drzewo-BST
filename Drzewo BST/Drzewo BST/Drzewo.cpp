#include "Drzewo.h"
#include <iostream>

using namespace std;

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
void Drzewo::usunElement(int wartosc) {
	elementDrzewa* temp = nullptr;
};

void Drzewo::usunDrzewo() {};

elementDrzewa* Drzewo::szukajElementu(int wartosc) {
	elementDrzewa* temp = korzen;

	while (temp->wartosc != wartosc){
		if (temp->wartosc == wartosc) return temp;
		if (wartosc < temp->wartosc)
		{
			temp = temp->lewy;
			
		}
		if (temp->wartosc < wartosc)
		{
			temp = temp->prawy;
			return temp;
		}
		cout << temp->wartosc;
	};

	return korzen;
};

void Drzewo::wyswietlDrzewo() {
	int komenda = 0;
	elementDrzewa temp = *korzen;

	cout << "0 - preorder, 1 - inorder, 2 - postorder\n>  ";
	cin >> komenda;
	switch (komenda)
	{
	case 0:
		while (true) {
			
		}
		break;

	default:
		break;
	}
};
void Drzewo::zapiszDoPliku() {
};
void Drzewo::wczytajZPliku() {
};

