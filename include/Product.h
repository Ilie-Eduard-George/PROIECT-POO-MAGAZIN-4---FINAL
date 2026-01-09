#pragma once

#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include "ProductCategory.h"
#include "Exceptions.h"

// Clasă abstractă (cerință: clasă abstractă)
class Product {
private:
    int id_{0};
    std::string name_;
    int storageGB_{0};
    int ramGB_{0};
    std::string color_;
    double purchasePrice_{0.0};
    int stock_{0};

    // Resursă dinamică pentru a justifica copy ctor / operator= (regula celor 3)
    std::unique_ptr<char[]> sku_;
    std::size_t skuLen_{0};

    // static non-trivial (cerință): map de conversie categorie->text
    static std::unordered_map<ProductCategory, std::string> categoryNames_;

protected:
    // Constructor folosit din derivate (cerință: apelare ctor bază din derivate)
    Product(ProductCategory category,
            std::string name,
            int storageGB,
            int ramGB,
            std::string color,
            double purchasePrice,
            int stock,
            std::string sku);

    ProductCategory category_{ProductCategory::Phone};

public:
    // Regula celor 3 (cerință)
    Product(const Product& other);
    Product& operator=(const Product& other);
    virtual ~Product(); // virtual (cerință)

    // Move (nu strică; nu e cerut explicit)
    Product(Product&&) noexcept = default;
    Product& operator=(Product&&) noexcept = default;

    // Getteri (const)
    int id() const { return id_; }
    ProductCategory category() const { return category_; }
    const std::string& name() const { return name_; }
    int storageGB() const { return storageGB_; }
    int ramGB() const { return ramGB_; }
    const std::string& color() const { return color_; }
    double purchasePrice() const { return purchasePrice_; }
    int stock() const { return stock_; }
    std::string sku() const;

    void setId(int id) { id_ = id; }

    // operator supraîncărcat ca funcție membră (cerință)
    Product& operator+=(int qty);
    Product& operator-=(int qty);

    // I/O (cerință: << și >>)
    virtual void print(std::ostream& os) const;
    virtual void read(std::istream& is);

    // Metodă polimorfă pentru copiere (Factory/Prototype-like util)
    virtual std::shared_ptr<Product> clone() const = 0;

    // static funcție non-trivială (cerință)
    static std::string categoryToString(ProductCategory c);

    // Prezentare de bază (fără preț)
    std::string basicLine() const;

    // Prezentare cu preț (salePrice dat din exterior)
    std::string lineWithPrice(double salePrice) const;
};

// operator<< / operator>> non-membre (cerință)
std::ostream& operator<<(std::ostream& os, const Product& p);
std::istream& operator>>(std::istream& is, Product& p);

// operator non-membru (cerință) - comparare după nume apoi id
bool operator<(const Product& a, const Product& b);
