#include <iostream>
#include <cmath>
using namespace std;

class complex{
private:
    int real;
    int imaginary;
public:
    complex(double r = 0.0, double i = 0.0) : real(r), imaginary(i) {}

    complex operator+(complex obj){
        return complex(real + obj.real, imaginary + obj.imaginary);
    }
    
    complex operator-(complex obj){
        return complex(real - obj.real, imaginary - obj.imaginary);
    }

    complex operator*(complex obj){
        return complex(real * obj.real, imaginary * obj.imaginary);
    }

    complex operator/(complex obj){
        return complex(real / obj.real, imaginary / obj.imaginary);
    }

    friend ostream& operator<<(ostream& out, complex obj){
        out << "(" << obj.real << " + "  << obj.imaginary << "i)";
        return out;
    }

    friend double magnitude(complex& obj){
        return sqrt(obj.real * obj.real + obj.imaginary * obj.imaginary);
    }

};

int main(){
    complex a(8, 9);
    complex b(5, 6);

    complex sum = a + b;
    complex difference = a - b;
    complex product = a * b;
    complex quotient = a / b;

    cout << magnitude(a) << endl;
    cout << magnitude(b) << endl;

    return 0;
}
