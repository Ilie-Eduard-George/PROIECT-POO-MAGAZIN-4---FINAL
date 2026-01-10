#include "Magazin.h"
#include <iostream>

void Magazin::adaugaProdus(const std::shared_ptr<Produs>& p) {
    stoc.push_back(p);
}

void Magazin::afisareStoc() const {
    if(stoc.empty()) { std::cout << "Stoc gol.\n"; return; }
    for(const auto& p : stoc)
        std::cout << *p << "\n";
}

std::shared_ptr<Produs> Magazin::cautaProdus(const std::string& nume) {
    for(auto& p : stoc) {
        if(p->getNume() == nume) return p;
    }
    std::cout << "Produsul nu exista in stoc.\n";
    return nullptr;
}