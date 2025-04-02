#include <iostream>
using namespace std;

class Car
{
private:
    string brand, model;
    float rentalprice;
    bool status;
    int days;
    double totalRevenue;
    string registrationno;

public:
    Car()
    {
        brand = "abd";
        model = "xyx";
        rentalprice = 0.0;
        status = true;
        days = 0;
        totalRevenue = 0.0;
        registrationno = "bb123";
    }

    Car(string b, string m, float p, bool s, int d, double t, string r){
        brand = b;
        model = m;
        rentalprice = p;
        status = s;
        days = d;
        totalRevenue = t;
        registrationno = r;
    }

    bool checkAvailability(){
        return status;

    }

    void update(string newbrand, string newmodel, float newprice, bool s){
        brand = newbrand;
        model = newmodel;
        rentalprice = newprice;
        status = s;
    }

    double applyDiscount(int days){
        if (days > 5 && days <= 10){
            return rentalprice * 0.95;
        }
        else if (days > 10){
            return rentalprice * 0.90;
        }
        else{
            return rentalprice;
        }
    }

    void rentCar()
    {
        cout << "Enter Number of days: ";
            cin >> this->days;
            cout << "Checking Availibility" << endl;
            if( status == true){
                double newPrice = applyDiscount(days);
                this->totalRevenue += newPrice*days;
                this->status = false;
                cout << "Car Rented" << endl;
            }
            else{
                cout << "Request Denied" << endl;
            }
    }
    void trackTotalRevenue(){
        cout << "Total Revenue for " << brand << " " << model <<
        ": $" << this->totalRevenue << endl;
    }

   
    Car(Car &other) : model(other.model), rentalprice(other.rentalprice) , brand(other.brand), status(other.status),
                    days(other.days), totalRevenue(other.totalRevenue),registrationno(other.registrationno)
    {
        cout << "car copy constructed";
    }
    ~Car()
    {
        cout << "destroyed" << model << "(" << rentalprice << ")";
    }
    void displayCarDetails() {
        cout << "Car Details:" << endl;
        cout << "Registration Number: " << registrationno << endl;
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Rental Price per day: $" << rentalprice << endl;
        cout << "Status: " << (status ? "Available" : "Rented") << endl;
        cout << "Total Revenue Generated: $" << totalRevenue << endl;
    }

    
    void returnCar(){
        status = true;
        cout << "Car with registration number " << registrationno << " is available for rent again." << endl;
    }

};
int main()
{
    Car car1("honda", "audi", 13000.0, true, 8, 0.0, "asbjsdj124");
    if(car1.checkAvailability()){
        cout << "Car is Available" << endl;
    }
    else{
        cout << "Car not available" << endl;
    }

    car1.rentCar();
    car1.trackTotalRevenue();
    car1.applyDiscount(4);
    car1.rentCar();
    
    Car car2(car1);
    car2.trackTotalRevenue();
    
    car1.update("toyota", "abc" , 4000.0, true);
    
    car1.trackTotalRevenue();
    car1.displayCarDetails();

    return 0;
}
