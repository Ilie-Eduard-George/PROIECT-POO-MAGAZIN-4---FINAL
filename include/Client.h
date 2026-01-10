#ifndef OOP_CLIENT_H
#define OOP_CLIENT_H

#include <string>
#include "Cos.h"
#include "Produs.h"

class Client {
private:
    std::string nume;
    int varsta;
    Cos<Produs> cos;

public:
    Client(const std::string& n = "", int v = 18);

    void adaugaInCos(const std::shared_ptr<Produs>& p);
    void veziCos() const;
    void cumpara();
};

#endif //OOP_CLIENT_H