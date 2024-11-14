#pragma once
#include <string>
#include <iostream>

struct elementDrzewa
{
	elementDrzewa* lewy;
	elementDrzewa* prawy;
	elementDrzewa* rodzic;
	std::string wartosc;

	elementDrzewa() : rodzic(nullptr), lewy(nullptr), prawy(nullptr), wartosc("NULL") {};
};

class Drzewo
{
	private:
		elementDrzewa* korzen;
	public:

		Drzewo();

		void dodajElement(std::string wartosc) ;
		void usunElement(std::string wartosc) ;
		void usunDrzewo() ;
		elementDrzewa* szukajElementu(std::string wartosc) ;
		void wyswietlDrzewo() ;
		void zapiszDoPliku() ;
		void wczytajZPliku();

};

