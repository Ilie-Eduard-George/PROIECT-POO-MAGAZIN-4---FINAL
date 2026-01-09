#pragma once
#include <memory>
#include <unordered_map>
#include <vector>
#include <string>
#include "Product.h"
#include "PricingEngine.h"
#include "MarketSimulator.h"
#include "History.h"

// A 3-a ierarhie (opțional dar util): tranzacții
class Transaction {
public:
    virtual ~Transaction() = default;
    virtual double total() const = 0;
    virtual std::string description() const = 0;
};

class SaleTransaction final : public Transaction {
private:
    int productId_{0};
    int qty_{0};
    double unitPrice_{0.0};

public:
    SaleTransaction(int productId, int qty, double unitPrice)
        : productId_(productId), qty_(qty), unitPrice_(unitPrice) {}

    double total() const override { return unitPrice_ * qty_; }
    std::string description() const override;
};

class PurchaseTransaction final : public Transaction {
private:
    int productId_{0};
    int qty_{0};
    double unitCost_{0.0};

public:
    PurchaseTransaction(int productId, int qty, double unitCost)
        : productId_(productId), qty_(qty), unitCost_(unitCost) {}

    double total() const override { return unitCost_ * qty_; }
    std::string description() const override;
};

class Store {
private:
    std::vector<std::shared_ptr<Product>> catalog_;              // STL container 1
    std::unordered_map<int, std::shared_ptr<Product>> byId_;     // STL container 2

    PricingEngine pricing_;
    MarketSimulator market_;

    // Template instanțieri (cerință)
    History<double> revenueHistory_;
    History<std::string> eventHistory_;

    void indexCatalog();

public:
    Store(PricingEngine pricing, MarketSimulator market);

    void seedInitialCatalog(); // 3 telefoane, 3 tablete, 3 laptopuri

    // Market tick: se cheamă după fiecare acțiune relevantă
    void tickMarketAndAnnounce();

    // Afișări
    void printCatalogBasic() const;          // fără preț
    void printCatalogWithSalePrices() const; // cu preț de vânzare curent

    // Operații de business
    void restock(int productId, int qty);       // cumpărare stoc (preț de cumpărare)
    SaleTransaction sell(int productId, int qty); // vânzare către client

    // vinde tot inventarul
    double sellAllInventory(double& outProfit);

    // Utilitare
    bool exists(int productId) const;
    const Product& getProduct(int productId) const;
    Product& getProductMut(int productId);

    double salePriceFor(int productId) const;

    // 2-3 metode cu downcast (cerință) - NU sunt I/O
    static int performanceScore(const Product& p);
    static double insuranceCost(const Product& p);
    static bool isHighDemand(const Product& p);

    // sortare (algoritm + lambda)
    void sortCatalogByCurrentSalePrice();

    // acces pentru mesaj event
    ProductCategory discountedCategory() const { return pricing_.discountedCategory(); }
};
