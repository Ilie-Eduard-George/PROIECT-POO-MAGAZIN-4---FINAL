#include <iostream>
#include <limits>
#include "Magazin.h"
#include "Client.h"
#include "Racheta.h"
#include "Incaltaminte.h"
#include "Imbracaminte.h"

int main() {
    Magazin magazin;
    Client client("Andrei", 20);

    // Adaugam produse in magazin
    magazin.adaugaProdus(std::make_shared<Racheta>("Wilson Pro", 450.0, 10, 68.0, "Wilson"));
    magazin.adaugaProdus(std::make_shared<Incaltaminte>("Nike Air", 350.0, 5, 42, "negru"));
    magazin.adaugaProdus(std::make_shared<Imbracaminte>("Tricou Adidas", 120.0, 20, 42, "alb"));

    int optiune;
    do {
        std::cout << "\n1. Vezi stoc\n2. Adauga in cos\n3. Vezi cos\n4. Cumpara\n5. Iesire\nAlege: ";
        if (!(std::cin >> optiune)) {
            std::cout << "Input invalid. Iesire...\n";
            return 0;
        }

        switch(optiune) {
            case 1:
                magazin.afisareStoc();
                break;
            case 2: {
                // Permite nume cu spatii (ex: "Wilson Pro").
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::string nume;
                std::cout << "Nume produs: ";
                std::getline(std::cin, nume);
                auto p = magazin.cautaProdus(nume);
                if(p) client.adaugaInCos(p);
                break;
            }
            case 3:
                client.veziCos();
                break;
            case 4:
                client.cumpara();
                break;
            case 5:
                std::cout << "La revedere!\n";
                break;
            default:
                std::cout << "Optiune invalida.\n";
        }

    } while(optiune != 5);

    return 0;
}