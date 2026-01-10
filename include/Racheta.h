#ifndef OOP_RACHETA_H
#define OOP_RACHETA_H

#include "Produs.h"
#include <string>

class Racheta : public Produs {
private:
    double lungime;
    std::string brand;

public:
    Racheta(const std::string& n = "", double p = 0.0, int s = 0, double l = 68.0, const std::string& b = "Unknown");
    Racheta(const Racheta& other);
    Racheta& operator=(const Racheta& other);
    virtual ~Racheta() = default;

    void afisare(std::ostream& out) const override;

    friend std::ostream& operator<<(std::ostream& out, const Racheta& r);
    friend std::istream& operator>>(std::istream& in, Racheta& r);

    friend Racheta operator-(const Racheta& r, double reducere);
};

#endif //OOP_RACHETA_H