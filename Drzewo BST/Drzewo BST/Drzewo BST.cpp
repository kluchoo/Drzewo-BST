#include <iostream>
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
}
	
