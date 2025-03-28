#include <iostream>
#include <string>
using namespace std;

class Product {
protected:
    string productID;
    string productName;
    float price;
    int stockQuantity;

public:
    Product(string id, string name, float p, int quantity)
        : productID(id), productName(name), price(p), stockQuantity(quantity) {}

    virtual void applyDiscount(float percentage) {
        price -= (price * percentage / 100);
    }

    virtual float calculateTotalPrice(int quantity) {
        return price * quantity;
    }

    virtual void displayProductInfo() const {
        cout << "Product ID: " << productID << endl;
        cout << "Name: " << productName << endl;
        cout << "Price: $" << price << endl;
        cout << "Stock: " << stockQuantity << endl;
    }

    float operator+(const Product& other) {
        return this->price + other.price;
    }

    void output(ostream& os) const {
        this->displayProductInfo();
    }
};

ostream& operator<<(ostream& os, const Product& product) {
    product.displayProductInfo();
    return os;
}

class Electronics : public Product {
protected:
    int warrantyPeriod;
    string brand;

public:
    Electronics(string id, string name, float p, int quantity, int warranty, string b)
        : Product(id, name, p, quantity), warrantyPeriod(warranty), brand(b) {}

    void displayProductInfo() const override {
        Product::displayProductInfo();
        cout << "Brand: " << brand << endl;
        cout << "Warranty: " << warrantyPeriod << " months" << endl;
    }
};

class Clothing : public Product {
protected:
    string size;
    string color;
    string fabricMaterial;

public:
    Clothing(string id, string name, float p, int quantity, string s, string c, string fm)
        : Product(id, name, p, quantity), size(s), color(c), fabricMaterial(fm) {}

    void applyDiscount(float percentage) override {
        price -= (price * percentage / 100);
    }
};

class FoodItem : public Product {
protected:
    string expirationDate;
    int calories;

public:
    FoodItem(string id, string name, float p, int quantity, string expDate, int cal)
        : Product(id, name, p, quantity), expirationDate(expDate), calories(cal) {}

    float calculateTotalPrice(int quantity) override {
        if (quantity > 10) {
            return price * quantity * 0.9;
        }
        return price * quantity;
    }
};

class Book : public Product {
protected:
    string author;
    string genre;

public:
    Book(string id, string name, float p, int quantity, string auth, string g)
        : Product(id, name, p, quantity), author(auth), genre(g) {}

    void displayProductInfo() const override {
        Product::displayProductInfo();
        cout << "Author: " << author << endl;
        cout << "Genre: " << genre << endl;
    }
};

int main() {
    Electronics phone("P100", "A8", 599.99, 50, 24, "Samsung");
    Clothing shirt("C200", "Polo", 29.99, 100, "M", "Blue", "Cotton");
    Book novel("B300", "Black", 14.99, 30, "Ali", "Fiction");

    cout << "Combined price of phone and shirt: $" << (phone + shirt) << endl;

    cout << "\nProduct Information:\n";
    cout << phone;
    cout << shirt;
    cout << novel;

    return 0;
}