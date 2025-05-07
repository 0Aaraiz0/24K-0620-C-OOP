#include <iostream>
#include <exception>
using namespace std;

class InvalidTemperatureException : public exception {};

template <class T>
void convertToFahrenheit(T celsius) {
    cout << "Attempting to convert " << celsius << "C..." << endl;
    if (celsius < -273.15) {
        throw InvalidTemperatureException();
    } else {
        T fahrenheit = (celsius * 9.0 / 5.0) + 32;
        cout << "Conversion successful: " << fahrenheit << "F" << endl;
    }
}

int main() {
    float a = 56.5;
    try {
        convertToFahrenheit(a);
    } catch (InvalidTemperatureException& e) {
        cout << "Caught InvalidTemperatureException - what(): " << e.what() << endl;
    }

    a = -300;
    try {
        convertToFahrenheit(a);
    } catch (InvalidTemperatureException& e) {
        cout << "Caught InvalidTemperatureException - what(): " << e.what() << endl;
    }

    return 0;
}
