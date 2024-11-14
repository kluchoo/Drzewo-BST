#pragma once
using namespace std;
#include <string>

struct elementDrzewa
{
	elementDrzewa* lewy;
	elementDrzewa* prawy;
	elementDrzewa* rodzic;
	string wartosc;

	elementDrzewa() : rodzic(nullptr), lewy(nullptr), prawy(nullptr), wartosc("NULL") {};
};

class Drzewo
{
	private:
		elementDrzewa* korzen;
	public:

		Drzewo();

		void dodajElement(string wartosc) {};
		void usunElement(string wartosc) {};
		void usunDrzewo() {};
		elementDrzewa* szukajElementu(string wartosc) {};
		void wyswietlDrzewo() {};
		void zapiszDoPliku() {};
		void wczytajZPliku() {}

};

