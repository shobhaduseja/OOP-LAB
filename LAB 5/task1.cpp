#include <iostream>
#include <string>
using namespace std;

class Apartment {
    int id;
    string address;
    string* ownerName;
public:
    Apartment(int id, string address, const string &owner) : id(id), address(address){
        ownerName = new string(owner);
    }
    Apartment(const Apartment &obj) : id(obj.id), address(obj.address) {
        ownerName = obj.ownerName;
    }

    ~Apartment() {
       cout << "Apartment Destroyed" << endl;
    }

    void displayDetails() const {
        cout << "your ID is : " << id << endl;
        cout << "your Address is : " << address << endl;
        cout << "Owner name is : " << *ownerName << endl;
    }
};

int main() {
    Apartment apt1(55, "nazimabad", "minal");
    Apartment apt2(888, "clifton", "shobha");

    apt1.displayDetails();
    apt2.displayDetails();
    Apartment apt1_copy(apt1); 

    apt1.displayDetails();
    apt1_copy.displayDetails();

    return 0;
}
