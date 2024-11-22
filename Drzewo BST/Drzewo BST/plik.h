#pragma once

#include "Drzewo.h"
#include <fstream>
#include <string>

class plik
{
public:
	plik();
	~plik();

	void zapiszDoPlikuBinarnego(elementDrzewa* element, std::ofstream& plik);
	void wczytajZPliku(std::string sciezka, Drzewo& drzewo);

	Drzewo drzewo;
private:
};