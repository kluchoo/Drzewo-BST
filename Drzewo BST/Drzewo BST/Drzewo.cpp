#include "Drzewo.h"
#include <iostream>
#include <fstream>

using namespace std;

/**
 * @brief Konstruktor klasy Drzewo.
 *
 * Inicjalizuje korzen drzewa jako nullptr oraz ilosc elementow jako 0.
 */
Drzewo::Drzewo() : korzen(nullptr), iloscElementow(0) {}

/**
 * @brief Dodaje nowy element do drzewa.
 *
 * @param wartosc Wartosc nowego elementu do dodania.
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
 * @brief Usuwa element o podanej wartosci z drzewa.
 *
 * @param wartosc Wartosc elementu do usuniecia.
 */
void Drzewo::usunElement(int wartosc) {
    elementDrzewa* elementUsuwany = szukajElementu(wartosc);
    if (elementUsuwany == nullptr) {
        cout << "Element nie zostal znaleziony.\n";
        return;
    }

    // Przypadek 1: Wezel ma dwoje dzieci
    if (elementUsuwany->lewy != nullptr && elementUsuwany->prawy != nullptr) {
        // Znajdz nastepnika (najwiekszy wezel w lewym poddrzewie)
        elementDrzewa* nastepca = elementUsuwany->lewy;
        while (nastepca->prawy != nullptr) {
            nastepca = nastepca->prawy;
        }

        // Skopiuj wartosc nastepnika do elementu usuwanego
        elementUsuwany->wartosc = nastepca->wartosc;

        // Usun nastepnika
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
    // Przypadek 2: Wezel ma jedno dziecko
    else if (elementUsuwany->lewy != nullptr || elementUsuwany->prawy != nullptr) {
        elementDrzewa* dziecko = (elementUsuwany->lewy != nullptr) ? elementUsuwany->lewy : elementUsuwany->prawy;

        // Podlacz dziecko do rodzica elementu usuwanego
        if (elementUsuwany->rodzic != nullptr) {
            if (elementUsuwany->rodzic->lewy == elementUsuwany) {
                elementUsuwany->rodzic->lewy = dziecko;
            }
            else {
                elementUsuwany->rodzic->prawy = dziecko;
            }
        }
        else {
            // Jezeli elementUsuwany jest korzeniem, aktualizujemy korzen drzewa
            korzen = dziecko;
        }

        dziecko->rodzic = elementUsuwany->rodzic;
        delete elementUsuwany;
    }
    // Przypadek 3: Wezel jest lisciem
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
            // Usuwamy korzen drzewa, gdy jest jedynym wezlem
            korzen = nullptr;
        }

        delete elementUsuwany;
    }
}

/**
 * @brief Usuwa cale drzewo.
 *
 * @param element Wskaznik na korzen drzewa.
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
 * @brief Szuka elementu o podanej wartosci w drzewie.
 *
 * @param wartosc Wartosc elementu do znalezienia.
 * @return elementDrzewa* Wskaznik na znaleziony element lub nullptr, jesli element nie zostal znaleziony.
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
 * @brief Wykonuje przejscie drzewa w porzadku preorder.
 *
 * @param element Wskaznik na korzen drzewa.
 */
void preorder(elementDrzewa* element) {
    if (!element) return;

    cout << element->wartosc << " ";
    preorder(element->lewy);
    preorder(element->prawy);
}

/**
 * @brief Wykonuje przejscie drzewa w porzadku inorder.
 *
 * @param element Wskaznik na korzen drzewa.
 */
void inorder(elementDrzewa* element) {
    if (!element) return;

    inorder(element->lewy);
    cout << element->wartosc << " ";
    inorder(element->prawy);
}

/**
 * @brief Wykonuje przejscie drzewa w porzadku postorder.
 *
 * @param element Wskaznik na korzen drzewa.
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
 * @param element Wskaznik na korzen drzewa.
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
 * @brief Wyswietla drzewo.
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