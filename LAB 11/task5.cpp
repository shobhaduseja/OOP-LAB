#include <iostream>
#include <exception>

class NegativeStockException : public std::exception {
public:
    const char* what() const noexcept override {
        return "std::exception";
    }
};

class OverCapacityException : public std::exception {
public:
    const char* what() const noexcept override {
        return "std::exception";
    }
};

template <typename T>
class InventoryItem {
private:
    T stock;
    T maxStock;

public:
    InventoryItem(T max) : stock(0), maxStock(max) {}

    void setStock(T value) {
        if (value < 0)
            throw NegativeStockException();
        else if (value > maxStock)
            throw OverCapacityException();
        stock = value;
    }

    T getStock() const {
        return stock;
    }
};

int main() {
    InventoryItem<int> item(100);  // max stock is 100

    try {
        std::cout << "Attempting to set stock to -5...\n";
        item.setStock(-5);
    } catch (const NegativeStockException& e) {
        std::cout << "Caught NegativeStockException - what(): " << e.what() << std::endl;
    }

    try {
        std::cout << "Attempting to set stock to 120 (max 100)...\n";
        item.setStock(120);
    } catch (const OverCapacityException& e) {
        std::cout << "Caught OverCapacityException - what(): " << e.what() << std::endl;
    }

    return 0;
}
