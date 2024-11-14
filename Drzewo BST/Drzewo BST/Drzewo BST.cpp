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
	drzewo.usunElement(3);
	cout << endl;
	if (drzewo.szukajElementu(3) != nullptr)
	{
		cout << drzewo.szukajElementu(3)->wartosc;
	}
	
