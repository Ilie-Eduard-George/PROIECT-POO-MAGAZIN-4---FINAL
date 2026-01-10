#include "Client.h"
#include <iostream>

Client::Client(const std::string& n, int v) : nume(n), varsta(v) {}

void Client::adaugaInCos(const std::shared_ptr<Produs>& p) {
    cos.adauga(p);
    std::cout << p->getNume() << " a fost adaugat in cos.\n";
}

void Client::veziCos() const {
    std::cout << "Cosul lui " << nume << ":\n";
    cos.afisare();
    std::cout << "Total: " << cos.total() << " RON\n";
}

void Client::cumpara() {
    std::cout << "Ati cumparat produse in valoare de: " << cos.total() << " RON\n";
    cos.goleste();
}