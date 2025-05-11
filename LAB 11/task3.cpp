#include <iostream>
#include <exception>

class InvalidTemperatureException : public std::exception {
public:
    const char* what() const noexcept override {
        return "std::exception";
    }
};

template <typename T>
double convertToFahrenheit(T celsius) {
    if (celsius < -273.15)
        throw InvalidTemperatureException();
    return (celsius * 9.0 / 5.0) + 32;
}

int main() {
    try {
        std::cout << "Attempting to convert -300C...\n";
        double fahrenheit = convertToFahrenheit(-300);
        std::cout << "Converted: " << fahrenheit << "F\n";
    } catch (const InvalidTemperatureException& e) {
        std::cout << "Caught InvalidTemperatureException - what(): " << e.what() << std::endl;
    }
    return 0;
}
