#include <iostream>
#include <string>

using namespace std;

class InventoryManager; 

class Car {
private:
    string model;
    double price;

public:
    Car(string m, double p) : model(m), price(p) {}

    friend class InventoryManager;
    friend void comparePrice(const Car& c1, const Car& c2);
};

class InventoryManager {
public:
    void updatePrice(Car& car, double newPrice) {
        car.price = newPrice;
        cout << "Updated price of " << car.model << " to $" << newPrice << "\n";
    }

    void displayCar(const Car& car) const {
        cout << "Model: " << car.model << ", Price: $" << car.price << "\n";
    }
};

void comparePrice(const Car& c1, const Car& c2) {
    cout << "Comparing prices of " << c1.model << " and " << c2.model << "...\n";
    if (c1.price > c2.price) {
        cout << c1.model << " is more expensive.\n";
    } else if (c1.price < c2.price) {
        cout << c2.model << " is more expensive.\n";
    } else {
        cout << "Both cars are priced equally.\n";
    }
}

int main() {
    InventoryManager manager;

    Car car1("Parado", 45000.0);
    Car car2("Mehran", 40000.0);

    cout << "Initial Inventory:\n";
    manager.displayCar(car1);
    manager.displayCar(car2);
    cout << "-------------------------\n";

    manager.updatePrice(car2, 47000.0);
    cout << "After Price Update:\n";
    manager.displayCar(car1);
    manager.displayCar(car2);
    cout << "-------------------------\n";

    comparePrice(car1, car2);

    return 0;
}
