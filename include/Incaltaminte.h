#ifndef OOP_INCALTAMINTE_H
#define OOP_INCALTAMINTE_H

#include "Produs.h"
#include <string>

class Incaltaminte : public Produs {
private:
    int marime;
    std::string culoare;

public:
    Incaltaminte(const std::string& n = "", double p = 0.0, int s = 0, int m = 40, const std::string& c = "alb");
    Incaltaminte(const Incaltaminte& other);
    Incaltaminte& operator=(const Incaltaminte& other);
    virtual ~Incaltaminte() = default;

    void afisare(std::ostream& out) const override;

    friend std::ostream& operator<<(std::ostream& out, const Incaltaminte& i);
    friend std::istream& operator>>(std::istream& in, Incaltaminte& i);
};

#endif // OOP_INCALTAMINTE_H