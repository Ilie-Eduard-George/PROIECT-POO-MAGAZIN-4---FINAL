#pragma once
#include <stdexcept>
#include <string>

// Bază pentru erori din magazin (derivată din std::exception prin std::runtime_error)
class StoreError : public std::runtime_error {
public:
    explicit StoreError(const std::string& msg) : std::runtime_error(msg) {}
};

class InputError : public StoreError {
public:
    explicit InputError(const std::string& msg) : StoreError("InputError: " + msg) {}
};

class NotFoundError : public StoreError {
public:
    explicit NotFoundError(const std::string& msg) : StoreError("NotFoundError: " + msg) {}
};

class OutOfStockError : public StoreError {
public:
    explicit OutOfStockError(const std::string& msg) : StoreError("OutOfStockError: " + msg) {}
};
