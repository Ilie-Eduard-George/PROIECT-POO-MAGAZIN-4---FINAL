#ifndef OOP_COS_H
#define OOP_COS_H

#include <vector>
#include <memory>
#include <iostream>

template <typename T>
class Cos {
private:
    std::vector<std::shared_ptr<T>> produse;

public:
    void adauga(const std::shared_ptr<T>& p);
    void afisare() const;
    double total() const;
    void goleste();
};

#endif //OOP_COS_H