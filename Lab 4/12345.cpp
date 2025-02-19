#include <iostream>
using namespace std;

class Car {
private:
    string brand;
    string model;
    double rentalPrice;
    bool availability;
    int carID;
    double totalRevenue;

public:
    Car() {
        brand = "Unknown";
        model = "Generic";
        rentalPrice = 0.0;
        availability = true;
        carID = 0;
        totalRevenue = 0.0;
    }

    Car(string b, string m, double price, bool avail, int id) {
        brand = b;
        model = m;
        rentalPrice = price;
        availability = avail;
        carID = id;
        totalRevenue = 0.0;
    }

    void setDetails(string b, string m, double price, bool avail, int id) {
        brand = b;
        model = m;
        rentalPrice = price;
        availability = avail;
        carID = id;
        totalRevenue = 0.0;
    }

    Car(const Car &obj) {
        brand = obj.brand;
        model = obj.model;
        rentalPrice = obj.rentalPrice;
        availability = obj.availability;
        carID = obj.carID;
        totalRevenue = obj.totalRevenue;
    }

    ~Car() {
        cout << "Car with ID " << carID << " is being removed from memory.\n";
    }

    void rentCar(int days) {
        if (availability) {
            applyDiscount(days);
            totalRevenue += rentalPrice * days;
            availability = false;
            cout << "Car " << carID << " rented for " << days << " days.\n";
        } else {
            cout << "Car " << carID << " is already rented!\n";
        }
    }

    void applyDiscount(int days) {
        if (days > 10) {
            rentalPrice *= 0.90; 
        } else if (days > 5) {
            rentalPrice *= 0.95; 
        }
    }

    void returnCar() {
        availability = true;
        cout << "Car " << carID << " has been returned and is now available.\n";
    }

    void display() {
        cout << "Car ID: " << carID << "\nBrand: " << brand << "\nModel: " << model
             << "\nRental Price: $" << rentalPrice << "\nAvailability: " 
             << (availability ? "Available" : "Rented") 
             << "\nTotal Revenue: $" << totalRevenue << "\n\n";
    }
};

int main() {
    Car car1;
    car1.display();

    Car car2("Toyota", "Camry", 50.0, true, 101);
    car2.display();

    Car car3 (car2); 
    cout << "Copy Constructor Test car 2 to car 3:\n";
    car3.display();

    car3.setDetails("Honda", "City", 60.0, true, 102);
    cout<<"car 3 after modification"<<endl;
    car3.display();
    cout<<"car 2 after modification of car 3 is unchanged"<<endl;
    car2.display();
    
    cout << "Renting Car 2\n";
    car2.rentCar(7); 

    cout << "Renting Car 3\n";
    car3.rentCar(3); 

    cout << "Car 2 Details after rental:\n";
    car2.display();
    
    cout << "Car 3 Details after rental:\n";
    car3.display();

    cout << "Returning Car 2...\n";
    car2.returnCar();
    
    cout << "Final Car Details:\n";
    car2.display();
    car3.display();

    return 0;
}
