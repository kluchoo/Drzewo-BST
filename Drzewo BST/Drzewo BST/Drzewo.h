#pragma once
#include <string>
#include <iostream>
#include <fstream>


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
		int iloscElementow;

	public:
		elementDrzewa* korzen;

		Drzewo();

		void dodajElement(int wartosc) ;
		void usunElement(int wartosc) ;
		void usunDrzewo() ;
		elementDrzewa* szukajElementu(int wartosc) ;
		void wyswietlDrzewo() ;
		void zapiszDoPliku(elementDrzewa* element, std::ofstream& plik);
		
};

