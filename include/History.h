#pragma once
#include <vector>
#include <ostream>
#include <stdexcept>

// Template folosit pentru istoric (cerință: template + 2 instanțieri)
template <typename T>
class History {
private:
    std::vector<T> items_;

public:
    void add(const T& item) { items_.push_back(item); }

    const T& last() const {
        if (items_.empty()) throw std::logic_error("History is empty");
        return items_.back();
    }

    std::size_t size() const { return items_.size(); }

    void clear() { items_.clear(); }

    void print(std::ostream& os) const {
        for (const auto& x : items_) os << x << "\n";
    }
};
