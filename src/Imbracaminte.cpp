#include "Imbracaminte.h"

#include <iostream>

Imbracaminte::Imbracaminte(const std::string& n, double p, int s, int m, const std::string& c)
    : Produs(n, p, s), marime(m), culoare(c) {}

Imbracaminte::Imbracaminte(const Imbracaminte& other)
    : Produs(other), marime(other.marime), culoare(other.culoare) {}

Imbracaminte& Imbracaminte::operator=(const Imbracaminte& other) {
    if (this != &other) {
        Produs::operator=(other);
        marime = other.marime;
        culoare = other.culoare;
    }
    return *this;
}

void Imbracaminte::afisare(std::ostream& out) const {
    Produs::afisare(out);
    out << ", Marime: " << marime << ", Culoare: " << culoare;
}

std::ostream& operator<<(std::ostream& out, const Imbracaminte& i) {
    i.afisare(out);
    return out;
}

std::istream& operator>>(std::istream& in, Imbracaminte& i) {
    in >> static_cast<Produs&>(i);
    std::cout << "Marime: ";
    in >> i.marime;
    std::cout << "Culoare: ";
    in >> i.culoare;
    return in;
}
