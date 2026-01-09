#pragma once
#include <string>
#include "ProductCategory.h"

// Simulează "pași" și declanșează evenimentul la fiecare N pași (alternează categoria redusă)
class MarketSimulator {
private:
    std::size_t step_{0};
    std::size_t triggerEvery_{5};
    ProductCategory currentDiscount_{ProductCategory::Phone};

public:
    explicit MarketSimulator(std::size_t triggerEvery = 5);

    // incrementează și întoarce mesaj dacă se declanșează eveniment
    // altfel întoarce string gol
    std::string tick();

    ProductCategory currentDiscount() const { return currentDiscount_; }
    std::size_t step() const { return step_; }
};
