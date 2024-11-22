#include "Drzewo.h"
#include <iostream>
#include <fstream>

using namespace std;

Drzewo::Drzewo() : korzen(nullptr), iloscElementow(0) {}

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

void Drzewo::usunElement(int wartosc) {
    elementDrzewa* elementUsuwany = szukajElementu(wartosc);
    if (elementUsuwany == nullptr) {
        cout << "Element nie zostal znaleziony.\n";
        return;
    }

    if (elementUsuwany->lewy != nullptr && elementUsuwany->prawy != nullptr) {
        elementDrzewa* nastepca = elementUsuwany->lewy;
        while (nastepca->prawy != nullptr) {
            nastepca = nastepca->prawy;
        }

        elementUsuwany->wartosc = nastepca->wartosc;

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
    else if (elementUsuwany->lewy != nullptr || elementUsuwany->prawy != nullptr) {
        elementDrzewa* dziecko = (elementUsuwany->lewy != nullptr) ? elementUsuwany->lewy : elementUsuwany->prawy;

        if (elementUsuwany->rodzic != nullptr) {
            if (elementUsuwany->rodzic->lewy == elementUsuwany) {
                elementUsuwany->rodzic->lewy = dziecko;
            }
            else {
                elementUsuwany->rodzic->prawy = dziecko;
            }
        }
        else {
            korzen = dziecko;
        }

        dziecko->rodzic = elementUsuwany->rodzic;
        delete elementUsuwany;
    }
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
            korzen = nullptr;
        }

        delete elementUsuwany;
    }
}

void Drzewo::usunDrzewo(elementDrzewa* element) {
    if (element == nullptr) {
        return;
    }

    usunDrzewo(element->lewy);
    usunDrzewo(element->prawy);

    std::cout << element->wartosc << std::endl;
    delete element;
}

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

void preorder(elementDrzewa* element) {
    if (!element) return;

    cout << element->wartosc << " ";
    preorder(element->lewy);
    preorder(element->prawy);
}

void inorder(elementDrzewa* element) {
    if (!element) return;

    inorder(element->lewy);
    cout << element->wartosc << " ";
    inorder(element->prawy);
}

void postorder(elementDrzewa* element) {
    if (!element) return;

    postorder(element->lewy);
    postorder(element->prawy);
    cout << element->wartosc << " ";
}

void Drzewo::zapiszDoPliku(elementDrzewa* element, std::ofstream& plik) {
    if (element != nullptr) {
        zapiszDoPliku(element->lewy, plik);
        plik << element->wartosc << " ";
        zapiszDoPliku(element->prawy, plik);
    }
}

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