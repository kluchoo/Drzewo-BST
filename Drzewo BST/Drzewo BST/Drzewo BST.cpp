#include <iostream>
#include "Drzewo.h"
using namespace std;

int main()
{

	Drzewo drzewo;

	drzewo.dodajElement(5);
	drzewo.dodajElement(2);
	drzewo.dodajElement(1);
	drzewo.dodajElement(3);
	cout << drzewo.szukajElementu(3)->wartosc;
	drzewo.usunElement(3);
	cout << drzewo.szukajElementu(3)->wartosc;


}
