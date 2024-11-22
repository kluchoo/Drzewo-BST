#include <iostream>
#include <fstream>
#include "Drzewo.h"
#include "plik.h"
using namespace std;

int main()
{

	Drzewo drzewo;
	plik plik;
	plik.wczytajZPliku("a.txt", drzewo);

	drzewo.wyswietlDrzewo();
}
	
