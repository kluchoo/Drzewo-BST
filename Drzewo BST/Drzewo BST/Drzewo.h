#pragma once
#include <string>
#include <iostream>

struct elementDrzewa
{
	elementDrzewa* lewy;
	elementDrzewa* prawy;
	elementDrzewa* rodzic;
	int wartosc;

	elementDrzewa() : rodzic(nullptr), lewy(nullptr), prawy(nullptr), wartosc{} {};
};

class Drzewo
{
	private:
		elementDrzewa* korzen;
		int iloscElementow;

	public:

		Drzewo();

		void dodajElement(int wartosc) ;
		void usunElement(int wartosc) ;
		void usunDrzewo() ;
		elementDrzewa* szukajElementu(int wartosc) ;
		void wyswietlDrzewo() ;
		void zapiszDoPliku() ;
		void wczytajZPliku();

};

