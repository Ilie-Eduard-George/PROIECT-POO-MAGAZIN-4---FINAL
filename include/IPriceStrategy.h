#pragma once
#include "Product.h"

// Strategy pattern: interfață pentru calcul preț de vânzare
class IPriceStrategy {
public:
    virtual ~IPriceStrategy() = default;
    virtual double computeSalePrice(const Product& p) const = 0;
};
