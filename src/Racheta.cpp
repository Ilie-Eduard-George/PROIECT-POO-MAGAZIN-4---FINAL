#include "Racheta.h"
#include <iostream>

Racheta::Racheta(const std::string& n, double p, int s, double l, const std::string& b)
    : Produs(n, p, s), lungime(l), brand(b) {}

Racheta::Racheta(const Racheta& other)
    : Produs(other), lungime(other.lungime), brand(other.brand) {}

Racheta& Racheta::operator=(const Racheta& other) {
    if(this != &other) {
        Produs::operator=(other);
        lungime = other.lungime;
        brand = other.brand;
    }
    return *this;
}

void Racheta::afisare(std::ostream& out) const {
    Produs::afisare(out);
    out << ", Lungime: " << lungime << " cm, Brand: " << brand;
}

std::ostream& operator<<(std::ostream& out, const Racheta& r) {
    r.afisare(out);
    return out;
}

std::istream& operator>>(std::istream& in, Racheta& r) {
    in >> static_cast<Produs&>(r);
    std::cout << "Lungime: "; in >> r.lungime;
    std::cout << "Brand: "; in >> r.brand;
    return in;
}

Racheta operator-(const Racheta& r, double reducere) {
    Racheta copie = r;
    copie.pret -= reducere;
    if(copie.pret < 0) copie.pret = 0;
    return copie;
}