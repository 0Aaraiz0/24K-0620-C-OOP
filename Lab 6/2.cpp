#include <iostream>
using namespace std;

class Vehicle { 
protected:
    string brand; 
    int speed;

public:
    Vehicle(string b, int s) {
        brand = b;
        speed = s;
    }

    virtual void displayDetails() {
        cout << "Brand: " << brand << endl;
        cout << "Speed: " << speed << " km/h" << endl;
    }
};

class Car : public Vehicle { 
protected:
    int seats; 

public:
    Car(string b, int s, int se) : Vehicle(b, s) {
        seats = se;
    }

    void displayDetails() override {
        Vehicle::displayDetails(); 
        cout << "Seats: " << seats << endl;
    }
};

class ElectricCar : public Car { 
    int batteryLife;

public:
    ElectricCar(string b, int s, int se, int bl) : Car(b, s, se) {
        batteryLife = bl;
    }

    void displayDetails() override {
        Car::displayDetails();
        cout << "Battery Life: " << batteryLife << " hours" << endl;
    }
};

int main() {
    string brand;
    int speed, seats, batteryLife;

    cout << "Enter brand: ";
    cin >> brand;
    cout << "Enter speed (km/h): ";
    cin >> speed;
    cout << "Enter seating capacity: ";
    cin >> seats;
    cout << "Enter battery life (hours): ";
    cin >> batteryLife;

    ElectricCar eCar(brand, speed, seats, batteryLife);

    cout << "\nVehicle Details:\n";
    eCar.displayDetails(); 

    return 0;
}
