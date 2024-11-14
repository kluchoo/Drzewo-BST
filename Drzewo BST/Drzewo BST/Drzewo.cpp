#include "Drzewo.h"
#include <iostream>

Drzewo::Drzewo() : korzen(nullptr) {};

void Drzewo::dodajElement(std::string wartosc) {};
void Drzewo::usunElement(std::string wartosc) {};
void Drzewo::usunDrzewo() {};
elementDrzewa* Drzewo::szukajElementu(std::string wartosc) {
	elementDrzewa* temp = nullptr;
	return temp;
};
void Drzewo::wyswietlDrzewo() {
	if (!korzen) {
		int typ = 0;
		std::cout << "\n0 - preorder, 1 - inorder, 2-postorder\n> ";
		std::cin >> typ;
		//int tenp = std::stoi(typ);
			elementDrzewa * temp = korzen;
		switch (typ)
		{
		case 0: //preorder
			do {

			} while (!(temp->rodzic));
			break;
		case 1:
			break;
		case 2:
			break;
		default:
			std::cout << "\nwybierz prawidlowy typ\n";
			break;
		}
	}
};
void Drzewo::zapiszDoPliku() {};
void Drzewo::wczytajZPliku() {};

