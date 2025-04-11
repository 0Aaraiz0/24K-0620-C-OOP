#include <iostream>
#include <cmath>

using namespace std;

class Complex {
private:
    double real;
    double imagine;

public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imagine(i) {}

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imagine + other.imagine);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imagine - other.imagine);
    }

    Complex operator*(const Complex& other) const {
        return Complex(
            real * other.real - imagine * other.imagine,
            real * other.imagine + imagine * other.real
        );
    }

    Complex operator/(const Complex& other) const {
        double denominator = other.real * other.real + other.imagine * other.imagine;
        if (denominator == 0) throw runtime_error("Division by zero!");
        return Complex(
            (real * other.real + imagine * other.imagine) / denominator,
            (imagine * other.real - real * other.imagine) / denominator
        );
    }

    friend double magnitude(const Complex& c);

    friend ostream& operator<<(ostream& os, const Complex& c);
};

double magnitude(const Complex& c) {
    return sqrt(c.real * c.real + c.imagine * c.imagine);
}

ostream& operator<<(ostream& os, const Complex& c) {
    os << "(" << c.real;
    if (c.imagine >= 0)
        os << " + " << c.imagine << "i)";
    else
        os << " - " << -c.imagine << "i)";
    return os;
}

int main() {
    Complex c1(3.0, 4.0);
    Complex c2(1.0, -2.0);

    Complex sum = c1 + c2;
    Complex difference = c1 - c2;
    Complex product = c1 * c2;
    Complex quotient = c1 / c2;

    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;
    cout << "Sum = " << sum << endl;
    cout << "Difference = " << difference << endl;
    cout << "Product = " << product << endl;
    cout << "Quotient = " << quotient << endl;
    cout << "Magnitude of c1 = " << magnitude(c1) << endl;
    cout << "Magnitude of c2 = " << magnitude(c2) << endl;

    return 0;
}
