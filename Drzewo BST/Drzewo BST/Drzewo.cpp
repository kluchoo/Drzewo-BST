#include "Drzewo.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/**
 * @brief Konstruktor klasy Drzewo.
 *
 * Inicjalizuje korze� drzewa jako nullptr oraz ilo�� element�w jako 0.
 */
Drzewo::Drzewo() : korzen(nullptr), iloscElementow{} {}

/**
 * @brief Dodaje nowy element do drzewa.
 *
 * @param wartosc Warto�� nowego elementu do dodania.
 */
void Drzewo::dodajElement(int wartosc) {
    elementDrzewa* nowyElement = new elementDrzewa;
    nowyElement->wartosc = wartosc;
    nowyElement->lewy = nullptr;
    nowyElement->prawy = nullptr;

    if (korzen == nullptr) {
        korzen = nowyElement;
        iloscElementow++;
    }
    else {
        elementDrzewa* sciezka = korzen;
        while (true) {
            if (nowyElement->wartosc > sciezka->wartosc) {
                if (sciezka->prawy != nullptr) {
                    sciezka = sciezka->prawy;
                }
                else {
                    sciezka->prawy = nowyElement;
                    iloscElementow++;
                    return;
                }
            }
            else {
                if (sciezka->lewy != nullptr) {
                    sciezka = sciezka->lewy;
                }
                else {
                    sciezka->lewy = nowyElement;
                    iloscElementow++;
                    return;
                }
            }
        }
    }
}

/**
 * @brief Usuwa element o podanej warto�ci z drzewa.
 *
 * @param wartosc Warto�� elementu do usuni�cia.
 */
void Drzewo::usunElement(int wartosc) {
    elementDrzewa* elementUsuwany = szukajElementu(wartosc);
    if (elementUsuwany == nullptr) {
        cout << "Element nie zostal znaleziony.\n";
        return;
    }

    // Przypadek 1: W�ze� ma dwoje dzieci
    if (elementUsuwany->lewy != nullptr && elementUsuwany->prawy != nullptr) {
        // Znajd� nast�pnika (najwi�kszy w�ze� w lewym poddrzewie)
        elementDrzewa* nastepca = elementUsuwany->lewy;
        while (nastepca->prawy != nullptr) {
            nastepca = nastepca->prawy;
        }

        // Skopiuj warto�� nast�pnika do elementu usuwanego
        elementUsuwany->wartosc = nastepca->wartosc;

        // Usu� nast�pnika
        if (nastepca->rodzic->lewy == nastepca) {
            nastepca->rodzic->lewy = nastepca->lewy;
        }
        else {
            nastepca->rodzic->prawy = nastepca->lewy;
        }

        if (nastepca->lewy != nullptr) {
            nastepca->lewy->rodzic = nastepca->rodzic;
        }

        delete nastepca;
    }
    // Przypadek 2: W�ze� ma jedno dziecko
    else if (elementUsuwany->lewy != nullptr || elementUsuwany->prawy != nullptr) {
        elementDrzewa* dziecko = (elementUsuwany->lewy != nullptr) ? elementUsuwany->lewy : elementUsuwany->prawy;

        // Pod��cz dziecko do rodzica elementu usuwanego
        if (elementUsuwany->rodzic != nullptr) {
            if (elementUsuwany->rodzic->lewy == elementUsuwany) {
                elementUsuwany->rodzic->lewy = dziecko;
            }
            else {
                elementUsuwany->rodzic->prawy = dziecko;
            }
        }
        else {
            // Je�eli elementUsuwany jest korzeniem, aktualizujemy korze� drzewa
            korzen = dziecko;
        }

        dziecko->rodzic = elementUsuwany->rodzic;
        delete elementUsuwany;
    }
    // Przypadek 3: W�ze� jest li�ciem
    else {
        if (elementUsuwany->rodzic != nullptr) {
            if (elementUsuwany->rodzic->lewy == elementUsuwany) {
                elementUsuwany->rodzic->lewy = nullptr;
            }
            else {
                elementUsuwany->rodzic->prawy = nullptr;
            }
        }
        else {
            // Usuwamy korze� drzewa, gdy jest jedynym w�z�em
            korzen = nullptr;
        }

        delete elementUsuwany;
    }
}

/**
 * @brief Usuwa ca�e drzewo.
 *
 * @param element Wska�nik na korze� drzewa.
 */
void Drzewo::usunDrzewo(elementDrzewa* element) {
    if (element == nullptr) {
        return;
    }

    usunDrzewo(element->lewy);
    usunDrzewo(element->prawy);

    std::cout << element->wartosc << std::endl;   // wypisanie  
    delete element;   // element usuwania
}

/**
 * @brief Szuka elementu o podanej warto�ci w drzewie.
 *
 * @param wartosc Warto�� elementu do znalezienia.
 * @return elementDrzewa* Wska�nik na znaleziony element lub nullptr, je�li element nie zosta� znaleziony.
 */
elementDrzewa* Drzewo::szukajElementu(int wartosc) {
    elementDrzewa* temp = korzen;
    while (temp) {
        cout << temp->wartosc << " ";

        if (wartosc < temp->wartosc) {
            if (temp->lewy == nullptr) {
                return nullptr;
            }
            temp = temp->lewy;
        }
        if (temp->wartosc < wartosc) {
            if (temp->prawy == nullptr) {
                return nullptr;
            }
            temp = temp->prawy;
        }

        if (temp->wartosc == wartosc) {
            cout << temp->wartosc << " ";
            return temp;
        }
    }
    return nullptr;
}

/**
 * @brief Wykonuje przej�cie drzewa w porz�dku preorder.
 *
 * @param element Wska�nik na korze� drzewa.
 */
void preorder(elementDrzewa* element) {
    if (!element) return;

    cout << element->wartosc << " ";
    preorder(element->lewy);
    preorder(element->prawy);
}

/**
 * @brief Wykonuje przej�cie drzewa w porz�dku inorder.
 *
 * @param element Wska�nik na korze� drzewa.
 */
void inorder(elementDrzewa* element) {
    if (!element) return;

    inorder(element->lewy);
    cout << element->wartosc << " ";
    inorder(element->prawy);
}

/**
 * @brief Wykonuje przej�cie drzewa w porz�dku postorder.
 *
 * @param element Wska�nik na korze� drzewa.
 */
void postorder(elementDrzewa* element) {
    if (!element) return;

    postorder(element->lewy);
    postorder(element->prawy);
    cout << element->wartosc << " ";
}

/**
 * @brief Zapisuje drzewo do pliku.
 *
 * @param element Wska�nik na korze� drzewa.
 * @param plik Referencja do strumienia pliku.
 */
void Drzewo::zapiszDoPliku(elementDrzewa* element, std::ofstream& plik) {
    if (element != nullptr) {
        zapiszDoPliku(element->lewy, plik);
        plik << element->wartosc << " ";
        zapiszDoPliku(element->prawy, plik);
    }
}

/**
 * @brief Wy�wietla drzewo.
 */
void Drzewo::wyswietlDrzewo() {
    int komenda = 0;
    if (korzen) elementDrzewa temp = *korzen; else if (korzen == nullptr) {
        cout << "Brak drzewa\n";
        return;
    }

    cout << "0 - preorder, 1 - inorder, 2 - postorder\n>  ";
    cin >> komenda;
    switch (komenda)
    {
    case 0:
        preorder(korzen);
        break;
    case 1:
        inorder(korzen);
        break;
    case 2:
        postorder(korzen);
        break;

    default:
        break;
    }
}