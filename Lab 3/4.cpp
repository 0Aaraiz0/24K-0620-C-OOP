#include <iostream>
using namespace std;

class Car {
private:
    string brand, model;
    float fuelCapacity, currentFuel;

public:
    Car(string b, string m, float capacity, float initialFuel) {
        brand = b;
        model = m;
        fuelCapacity = capacity;
        currentFuel = initialFuel;
    }

    void drive(float distance) {
        float fuelConsumed = distance * 0.3;
        if (fuelConsumed > currentFuel) {
            cout << "Not enough fuel to drive " << distance << " km!\n";
        } else {
            currentFuel -= fuelConsumed;
            cout << "Drove " << distance << " km. Fuel left: " << currentFuel << "L\n";
            checkFuelStatus();
        }
    }

    void refuel(float fuel) {
        if (currentFuel + fuel > fuelCapacity) 
        {
            cout<<"Not enough capcity"<<endl;
        }
        else if (currentFuel + fuel == fuelCapacity)
        {
            cout << "Tank full! Added " << (fuelCapacity - currentFuel) << "L.\n";
            currentFuel = fuelCapacity;
        } 
        else 
        {
            currentFuel += fuel;
            cout << "Added " << fuel << "L. Current fuel: " << currentFuel << "L\n";
        }
    }

    void checkFuelStatus() {
        cout << "Fuel Level: " << currentFuel << "L / " << fuelCapacity << "L\n";
        if (currentFuel <= fuelCapacity * 0.1) cout << "Low Fuel\n";
    }
};

int main() {
    Car car("Toyota", "Corolla", 50, 10);
    int choice;
    float value;

    while (true) {
        cout << "\n1. Drive\n";
        cout<<"2. Refuel\n";
        cout<<"3. Check Fuel Status\n";
        cout<<"4. Exit";
        cout<<"\nEnter choice: ";
        cin >> choice;
        if (choice == 1) {
            cout << "Enter distance to drive (km): ";
            cin >> value;
            car.drive(value);
        } else if (choice == 2) {
            cout << "Enter fuel amount to add (L): ";
            cin >> value;
            car.refuel(value);
        } else if (choice == 3) car.checkFuelStatus();
        else if (choice == 4) break;
        else cout << "Invalid choice. Try again.\n";
    }
}
