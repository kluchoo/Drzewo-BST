#include <iostream>
#include <fstream>
#include "Drzewo.h"
#include "plik.h"
using namespace std;

int main()
{

	Drzewo drzewo;
	plik plik;
	int komenda = 0;
	int a;
	while (komenda == 0) {
		system("cls");
		cout << "komendy:\n1 - dodaj element\n2 - usun element\n3 - usun cale drzewo\n4 - szukaj drogi do podanego elementu\n5 - wyswietlanie drzewa\n6 - zapisywanie do pliku zwyczajnie, 7 - binarnie\n8 - wczytywanie z pliku";
		cout << "\nkomenda: ";
		cin >> komenda;
		switch (komenda)
		{
		case 1:
			cout << "\nWartosc elementu: ";
			cin >> a;
			drzewo.dodajElement(a);
			break;
		case 2:
			cout << "\nWartosc elementu: ";
			cin >> a;
			drzewo.usunElement(a);
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		default:
			break;
		}
	}
	



	plik.wczytajZPliku("a.txt", drzewo);

	drzewo.wyswietlDrzewo();
}
	
