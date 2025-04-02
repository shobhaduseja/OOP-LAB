#include <iostream>
using namespace std;

class Product {
protected:
    int ID;
    string Name;
    double price;
    int stockQuantity;



public:
    Product(int id, string n, double p, int sq) : ID(id), Name(n), price(p), stockQuantity(sq) {}

    virtual void applyDiscount() {
        price *= 0.8;
    }

    virtual double totalprice(int quantity) {
        return quantity * price;
    }

    virtual void displayProductInfo() {
        cout << "your id: " << ID << endl;
        cout << "your name: " << Name << endl;
        cout << "Price: " << price << endl;
        cout << "quantity: " << stockQuantity << endl;
    }

    double getPrice(){
        return price;
    }

    string getName(){
        return Name;
    }

    Product operator+(Product& other) {
        return Product(0, "in bulk", this->price + other.price, 0);
    }

    void operator<<(Product& product) {
        product.displayProductInfo();
    }
};

class Electronics : public Product {
    int warranty;
    string brand;

public:
    Electronics(int id, string n, double p, int sq, int w, string b) 
        : Product(id, n, p, sq), warranty(w), brand(b) {}

    void displayProductInfo() override {
        Product::displayProductInfo();
        cout << "warranty: " << warranty << " years" << endl;
        cout << "brand: " << brand << endl;
    }
};

class Clothing : public Product {
    int size;
    string color;
    string fabricMaterial;

public:
    Clothing(int id, string n, double p, int sq, int s, string c, string fm) 
        : Product(id, n, p, sq), size(s), color(c), fabricMaterial(fm) {}

    void applyDiscount() override {
        if (fabricMaterial == "lawn") {
            price *= 0.8;
        } else if (fabricMaterial == "jorjed") {
            price *= 0.3;
        } else {
            price *= 0.4;
        }
    }

    void displayProductInfo() override {
        Product::displayProductInfo();
        cout << "size: " << size << endl;
        cout << "color: " << color << endl;
        cout << "fabric " << fabricMaterial << endl;
    }
};

class FoodItem : public Product {
    string expirationDate;
    int calories;

public:
    FoodItem(int id, string n, double p, int sq, string expDate, int cal) 
        : Product(id, n, p, sq), expirationDate(expDate), calories(cal) {}

    double totalprice(int quantity) override {
        double total = quantity * price;
        if (quantity > 10) {
            total *= 0.9;
        }
        return total;
    }

    void displayProductInfo() override {
        Product::displayProductInfo();
        cout << "expire Date: " << expirationDate << endl;
        cout << "Calories: " << calories <<  endl;
    }
};

class Book : public Product {
    string author;
    string genre;

public:
    Book(int id, string n, double p, int sq, string a, string g) 
        : Product(id, n, p, sq), author(a), genre(g) {}

    void displayProductInfo() override {
        Product::displayProductInfo();
        cout << "Author: " << author << endl;
        cout << "Genre: " << genre << endl;
    }
};

int main() {
    Electronics mobile(1, "mobile", 4343.3, 10, 2, "iphone");
    Clothing frock(2, "frock", 100, 2, 23, "yellow", "lawn");
    FoodItem burger(3, "burger", 22, 30, "11-23-2020", 600);
    Book novel(4, "true love", 108, 177, "collen hover", "Fiction");

    mobile.displayProductInfo();

    frock.applyDiscount();
    frock.displayProductInfo();

    burger.totalprice(34);
    burger.displayProductInfo();

    Product bundle = mobile + burger;
    cout << "Bundle Total Price: " << bundle.getPrice() << endl;

    cout << "mobile Details: ";
    mobile << mobile;

    cout << "frock Details: ";
    frock << frock;

    return 0;
}