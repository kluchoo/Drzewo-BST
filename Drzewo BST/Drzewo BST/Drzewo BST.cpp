#include <iostream>
#include <fstream>
#include "Drzewo.h"
using namespace std;

int main()
{

	Drzewo drzewo;

	drzewo.dodajElement(5);
	drzewo.dodajElement(2);
	drzewo.dodajElement(1);
	cout << "Dodanie elementu";
	cout << endl;
	drzewo.wyswietlDrzewo();
	ofstream file("a.txt");
	if (file.is_open()) {
		drzewo.zapiszDoPliku(drzewo.korzen, file);
		file.close();
		cout << "pliki zapisane do drzewa";
	}
}
	
