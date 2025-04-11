#include <iostream>
#include <string>
using namespace std;


class InventoryManager;

class Car {
private:
    string modelname;
    double price;

public:
    Car(string m = "", double p = 0.0) : modelname(m), price(p) {}

    friend class InventoryManager;
    friend void compareprice(Car& c1, Car& c2);
};



class InventoryManager {
public:
    void updateprice(Car& c, double newprice) {
        c.price = newprice;
    }

    void displayCar(Car& c) {
        cout << "Model name: " << c.modelname << endl;
        cout << "Price: " << c.price << endl;
    }
};


void compareprice(Car& c1, Car& c2) {
    if (c1.price > c2.price)
        cout << c1.modelname << " is expensive." << endl;
    else if (c2.price > c1.price)
        cout << c2.modelname << " is expensive." << endl;
    else
        cout << "same same" << endl;
}


int main() {
  
    InventoryManager manager;
    Car car1("sonata baby", 120000.0);
    Car car2("elantra janu", 230000.0);

    manager.displayCar(car1);
    manager.displayCar(car2);
    manager.updateprice(car1, 830000.0);
    manager.displayCar(car1);
    manager.displayCar(car2);
    compareprice(car1, car2);
    return 0;
}
