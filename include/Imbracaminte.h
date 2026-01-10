#ifndef OOP_IMBRACAMINTE_H
#define OOP_IMBRACAMINTE_H

#include "Produs.h"

#include <string>

class Imbracaminte : public Produs {
private:
    int marime;
    std::string culoare;

public:
    Imbracaminte(const std::string& n = "", double p = 0.0, int s = 0, int m = 42, const std::string& c = "negru");
    Imbracaminte(const Imbracaminte& other);
    Imbracaminte& operator=(const Imbracaminte& other);
    ~Imbracaminte() override = default;

    void afisare(std::ostream& out) const override;

    friend std::ostream& operator<<(std::ostream& out, const Imbracaminte& i);
    friend std::istream& operator>>(std::istream& in, Imbracaminte& i);
};

#endif // OOP_IMBRACAMINTE_H
