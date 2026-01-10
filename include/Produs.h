#ifndef OOP_PRODUS_H
#define OOP_PRODUS_H

#include <iostream>
#include <string>

class Produs {
protected:
    std::string nume;
    double pret;
    int stoc;

public:
    Produs(const std::string& n = "", double p = 0.0, int s = 0);
    Produs(const Produs& other);
    virtual ~Produs();

    Produs& operator=(const Produs& other);

    virtual void afisare(std::ostream& out) const;
    virtual void cumpara(int cantitate);

    double getPret() const;
    int getStoc() const;
    std::string getNume() const;

    friend std::ostream& operator<<(std::ostream& out, const Produs& p);
    friend std::istream& operator>>(std::istream& in, Produs& p);
};

#endif //OOP_PRODUS_H