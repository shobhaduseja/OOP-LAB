#include <iostream>
#include <string>

using namespace std;

class MenuItem {
protected:
    string dishName;
    double price;

public:
    MenuItem(string name, double p) : dishName(name), price(p) {}

    virtual void showDetails() = 0;
    virtual void prepare() = 0;
};

class Appetizer : public MenuItem {
public:
    Appetizer(string name, double p) : MenuItem(name, p) {}

    void showDetails() {
        cout << "Appetizer: " << dishName << endl;
        cout << "Price: " << price << endl;
    }

    void prepare() {
        cout << "Preparing : " << dishName << endl;
    }
};

class MainCourse : public MenuItem {
public:
    MainCourse(string name, double p) : MenuItem(name, p) {}

    void showDetails() {
        cout << "Main Course: " << dishName << endl;
        cout << "Price: " << price << endl;
    }

    void prepare() {
        cout << "Preparing main course: " << dishName << endl;
    }
};

int main() {
    MenuItem* dish1 = new Appetizer("pizza", 34.9);
    MenuItem* dish2 = new MainCourse("paneer handi", 98.99);

    dish1->showDetails();
    dish1->prepare();

    dish2->showDetails();
    dish2->prepare();

    delete dish1;
    delete dish2;

    return 0;
