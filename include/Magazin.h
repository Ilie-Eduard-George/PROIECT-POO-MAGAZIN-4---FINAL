#ifndef OOP_MAGAZIN_H
#define OOP_MAGAZIN_H

#include <vector>
#include <memory>
#include "Produs.h"

class Magazin {
private:
    std::vector<std::shared_ptr<Produs>> stoc;

public:
    void adaugaProdus(const std::shared_ptr<Produs>& p);
    void afisareStoc() const;
    std::shared_ptr<Produs> cautaProdus(const std::string& nume);
};
#endif //OOP_MAGAZIN_H