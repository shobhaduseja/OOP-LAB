#include <iostream>
using namespace std;

class Employee{
    protected:
        string name;
        double salary;

    public:
        Employee(string n, double s) : name(n), salary(s){}

        void display(){
            cout << "your name: " << name << endl;
            cout << "your salary: " << salary << endl;
        }
};

class Manager : public Employee{
    protected:
        double bonus;

    public:
        Manager(string n, double s, double b) : Employee(n, s+b),
            bonus(b){}

        void display(){
            Employee::display();
            cout << "Bonus: " << bonus << endl;
        }
};

int main(){
    Manager m1("shobha", 32000.00, 500.00);

    m1.display();
}
