// NOTE: Pentru template-uri, implementările trebuie să fie vizibile la instanțiere.
// Aici folosim instanțiere explicită pentru Cos<Produs>.

#include "Cos.h"
#include "Produs.h"

#include <memory>

template <typename T>
void Cos<T>::adauga(const std::shared_ptr<T>& p) {
    produse.push_back(p);
}

template <typename T>
void Cos<T>::afisare() const {
    if(produse.empty()) {
        std::cout << "Cosul este gol.\n";
        return;
    }
    for(const auto& p : produse)
        std::cout << *p << "\n";
}

template <typename T>
double Cos<T>::total() const {
    double s = 0.0;
    for(const auto& p : produse)
        s += p->getPret();
    return s;
}

template <typename T>
void Cos<T>::goleste() {
    produse.clear();
}

template class Cos<Produs>;