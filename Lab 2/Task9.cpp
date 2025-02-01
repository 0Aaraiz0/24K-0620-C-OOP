#include <iostream>

using namespace std;

struct Product {
    int productID;
    string name;
    int quantity;
    double price;
};

int main() {
    int size;
    double totalValue = 0;

    cout << "Enter the number of products: ";
    cin >> size;

    Product* inventory = new Product[size];

    for (int i = 0; i < size; i++) {
        cout << "Enter details for product " << i + 1 << endl;
        cout << "Product ID: ";
        cin >> inventory[i].productID;
        cout << endl;
        cout << "Name: ";
        cin >> inventory[i].name;  
        cout << endl;      
        cout << "Quantity: ";
        cin >> inventory[i].quantity;
        cout << endl;
        cout << "Price: ";
        cin >> inventory[i].price;
        cout << endl;
    }

    for (int i = 0; i < size; i++) {
        totalValue += inventory[i].quantity * inventory[i].price;
    }

    cout << "Total inventory value: " << totalValue << endl;

    delete[] inventory;

    return 0;
}
