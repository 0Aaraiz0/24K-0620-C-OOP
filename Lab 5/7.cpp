#include <iostream>
using namespace std;

class Product {
    string name;
    int ID, quantity;

public:
    Product() {} 
    Product(string n, int i, int q) {
        name = n;
        ID = i;
        quantity = q;
    }

    string getName() const {
        return name;
    }
    int getID() const {
        return ID;
    }

    void display() const {
        cout << "Name: " << name << endl;
        cout << "ID: " << ID << endl;
        cout << "Quantity: " << quantity << endl;
    }
};

class Inventory {
    Product* products;
    int productCount;
    int maxProducts;

public:
    Inventory(int maxp) {
        productCount = 0;
        maxProducts = maxp;
        products = new Product[maxProducts];
    }

    ~Inventory() {
        delete[] products; 
    }

    void addProduct(Product p) {
        if (productCount < maxProducts) {
            products[productCount] = p;
            productCount++;
        } else {
            cout << "Not enough space in inventory!" << endl;
        }
    }

    void sortProducts() {
        for (int i = 0; i < productCount - 1; i++) {
            for (int j = i + 1; j < productCount; j++) {
                if (products[i].getName() > products[j].getName()) {
                    swap(products[i], products[j]);
                }
            }
        }
    }

    void search(int ID) {
        for (int i = 0; i < productCount; i++) {
            if (ID == products[i].getID()) {
                products[i].display();
                return;
            }
        }
        cout << "Product not found!" << endl;
    }

    void displayAll() {
        for (int i = 0; i < productCount; i++) {
            products[i].display();
            cout << "-------------------" << endl;
        }
    }
};

int main() {
    int maxSize;
    cout << "Enter maximum inventory size: ";
    cin >> maxSize;

    Inventory inventory(maxSize);

    int choice;
    do {
        cout << "\n1. Add Product\n2. Sort Products\n3. Search by ID\n4. Display All Products\n5. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            string name;
            int id, quantity;
            cout << "Enter product name: ";
            cin >> name;
            cout << "Enter product ID: ";
            cin >> id;
            cout << "Enter quantity: ";
            cin >> quantity;
            inventory.addProduct(Product(name, id, quantity));

        } else if (choice == 2) {
            inventory.sortProducts();
            cout << "Products sorted alphabetically by name.\n";

        } else if (choice == 3) {
            int searchID;
            cout << "Enter product ID to search: ";
            cin >> searchID;
            inventory.search(searchID);

        } else if (choice == 4) {
            inventory.displayAll();

        } else if (choice == 5) {
            cout << "Exiting program.\n";
        } else {
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
