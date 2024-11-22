#pragma once

#include "Drzewo.h"
#include <fstream>

class plik
{
public:
	plik();
	~plik();

	void zapiszDoPlikuBinarnego();
	void wczytajZPliku();

	Drzewo drzewo;
private:
};

plik::plik()
{
}

plik::~plik()
{
}
