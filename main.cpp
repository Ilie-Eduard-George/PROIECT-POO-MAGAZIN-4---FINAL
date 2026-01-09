#include <iostream>
#include <limits>
#include <memory>
#include <string>

#include "Store.h"
#include "PriceStrategies.h"
#include "Exceptions.h"

static int readInt(const std::string& prompt) {
    std::cout << prompt;
    int x;
    if (!(std::cin >> x)) {
        throw InputError("Valoare intreaga invalida");
    }
    return x;
}

static int readPositiveInt(const std::string& prompt) {
    int x = readInt(prompt);
    if (x <= 0) throw InputError("Numarul trebuie sa fie > 0");
    return x;
}

static void printMenu() {
    std::cout << "\n==============================\n";
    std::cout << " MAGAZIN: telefoane/tablete/laptopuri\n";
    std::cout << "==============================\n";
    std::cout << "1) Afiseaza catalog (fara pret)\n";
    std::cout << "2) Aprovizionare (cumpara stoc)\n";
    std::cout << "3) Vinde un produs (catre client)\n";
    std::cout << "4) Vinde tot inventarul\n";
    std::cout << "5) Afiseaza catalog (cu pret de vanzare)\n";
    std::cout << "6) Sorteaza catalog dupa pretul de vanzare (sort + lambda)\n";
    std::cout << "0) Iesire\n";
}

int main() {
    try {
        PricingEngine pricing(std::make_shared<Markup15Strategy>(),
                              std::make_shared<Discount80Strategy>());

        MarketSimulator market(5); // la fiecare 5 pasi se schimba categoria redusa
        Store store(pricing, market);
        store.seedInitialCatalog();

        while (true) {
            printMenu();
            int opt = -1;

            try {
                opt = readInt("Alege optiunea: ");
            } catch (const StoreError& e) { // catch derivat
                std::cout << e.what() << "\n";
                // curata stream
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            if (opt == 0) {
                std::cout << "La revedere!\n";
                break;
            }

            try {
                switch (opt) {
                    case 1: {
                        store.printCatalogBasic();
                        store.tickMarketAndAnnounce();
                        break;
                    }
                    case 2: {
                        store.printCatalogBasic();
                        int id = readInt("Introdu ID produs pentru aprovizionare: ");
                        int qty = readPositiveInt("Introdu numarul de bucati: ");
                        store.restock(id, qty);
                        store.tickMarketAndAnnounce();
                        break;
                    }
                    case 3: {
                        store.printCatalogWithSalePrices();
                        int id = readInt("Alege ID produs de vandut: ");
                        std::cout << "Introdu numarul de bucati: ";
                        int qty;
                        if (!(std::cin >> qty)) throw InputError("Cantitate invalida");
                        if (qty <= 0) throw InputError("Cantitatea trebuie sa fie > 0");

                        // Inca un exemplu de utilizare metode cu downcast (nu e I/O cerut)
                        const Product& p = store.getProduct(id);
                        std::cout << "Info extra (score performanta): " << Store::performanceScore(p)
                                  << " | cost asigurare: " << Store::insuranceCost(p)
                                  << " | cerere mare: " << (Store::isHighDemand(p) ? "da" : "nu") << "\n";

                        store.sell(id, qty);
                        store.tickMarketAndAnnounce();
                        break;
                    }
                    case 4: {
                        double profit = 0.0;
                        const double revenue = store.sellAllInventory(profit);
                        std::cout << "\nInventar vandut complet!\n";
                        std::cout << "Valoare totala incasata: " << revenue << " lei\n";
                        std::cout << "Profit total (poate fi negativ): " << profit << " lei\n";
                        store.tickMarketAndAnnounce();
                        break;
                    }
                    case 5: {
                        store.printCatalogWithSalePrices();
                        store.tickMarketAndAnnounce();
                        break;
                    }
                    case 6: {
                        store.sortCatalogByCurrentSalePrice();
                        std::cout << "Catalog sortat dupa pretul de vanzare curent.\n";
                        store.printCatalogWithSalePrices();
                        store.tickMarketAndAnnounce();
                        break;
                    }
                    default:
                        std::cout << "Optiune invalida.\n";
                        break;
                }
            } catch (const StoreError& e) {
                // upcasting in catch: prinde baza StoreError (derivata din std::exception)
                std::cout << "\nEroare: " << e.what() << "\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } catch (const std::exception& e) {
                // upcast la std::exception
                std::cout << "\nEroare neasteptata: " << e.what() << "\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }

    } catch (const std::exception& e) {
        std::cout << "Fatal: " << e.what() << "\n";
        return 1;
    }
    return 0;
}
