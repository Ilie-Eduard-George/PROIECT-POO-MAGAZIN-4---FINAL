#include "Incaltaminte.h"
#include <iostream>

Incaltaminte::Incaltaminte(const std::string& n, double p, int s, int m, const std::string& c)
    : Produs(n,p,s), marime(m), culoare(c) {}

Incaltaminte::Incaltaminte(const Incaltaminte& other)
    : Produs(other), marime(other.marime), culoare(other.culoare) {}

Incaltaminte& Incaltaminte::operator=(const Incaltaminte& other) {
    if(this != &other) {
        Produs::operator=(other);
        marime = other.marime;
        culoare = other.culoare;
    }
    return *this;
}

void Incaltaminte::afisare(std::ostream& out) const {
    Produs::afisare(out);
    out << ", Marime: " << marime << ", Culoare: " << culoare;
}

std::ostream& operator<<(std::ostream& out, const Incaltaminte& i) {
    i.afisare(out);
    return out;
}

std::istream& operator>>(std::istream& in, Incaltaminte& i) {
    in >> static_cast<Produs&>(i);
    std::cout << "Marime: "; in >> i.marime;
    std::cout << "Culoare: "; in >> i.culoare;
    return in;
}