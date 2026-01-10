#include "Produs.h"
#include <iostream>

Produs::Produs(const std::string& n, double p, int s)
    : nume(n), pret(p), stoc(s) {}

Produs::Produs(const Produs& other)
    : nume(other.nume), pret(other.pret), stoc(other.stoc) {}

Produs::~Produs() {}

Produs& Produs::operator=(const Produs& other) {
    if(this != &other) {
        nume = other.nume;
        pret = other.pret;
        stoc = other.stoc;
    }
    return *this;
}

void Produs::afisare(std::ostream& out) const {
    out << "Nume: " << nume << ", Pret: " << pret << ", Stoc: " << stoc;
}

void Produs::cumpara(int cantitate) {
    if(cantitate > stoc) {
        std::cerr << "Stoc insuficient!\n";
        return;
    }
    stoc -= cantitate;
}

double Produs::getPret() const { return pret; }
int Produs::getStoc() const { return stoc; }
std::string Produs::getNume() const { return nume; }

std::ostream& operator<<(std::ostream& out, const Produs& p) {
    p.afisare(out);
    return out;
}

std::istream& operator>>(std::istream& in, Produs& p) {
    std::cout << "Nume: "; in >> p.nume;
    std::cout << "Pret: "; in >> p.pret;
    std::cout << "Stoc: "; in >> p.stoc;
    return in;
}