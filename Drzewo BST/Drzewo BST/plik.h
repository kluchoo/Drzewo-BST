#pragma once

#include "Drzewo.h"
#include <fstream>
#include <string>

class plik
{
public:
	plik();
	~plik();

public:
	void zapiszDoPlikuBinarnego(elementDrzewa* element, const std::string& plik);
	void wczytajZPliku(std::string sciezka, Drzewo& drzewo);
private:
	void zapiszElementDoPlikuBinarnego(elementDrzewa* element, std::ofstream& file);
	Drzewo drzewo;

private:
};