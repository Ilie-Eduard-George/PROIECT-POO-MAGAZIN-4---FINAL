#pragma once
#include "IPriceStrategy.h"

// +15% adaos (cerință)
class Markup15Strategy final : public IPriceStrategy {
public:
    double computeSalePrice(const Product& p) const override {
        return p.purchasePrice() * 1.15;
    }
};

// 80% din prețul de cumpărare (eveniment piață)
class Discount80Strategy final : public IPriceStrategy {
public:
    double computeSalePrice(const Product& p) const override {
        return p.purchasePrice() * 0.80;
    }
};
