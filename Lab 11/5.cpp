#include <iostream>
#include <exception>
using namespace std;

class NegativeStockException : public exception {};

class OverCapacityException : public exception {};

template <class T>
class InventoryItem {
    T stock;
    T max;
public:
    InventoryItem(T value, T maxLimit) {
        cout << "Attempting to set stock to " << value;
        max = maxLimit;

        if (value < 0) {
            cout << "..." << endl;
            throw NegativeStockException();
        } else if (value > max) {
            cout << " (max " << max << ")..." << endl;
            throw OverCapacityException();
        } else {
            cout << "..." << endl;
            stock = value;
            cout << "Successful Set" << endl;
        }
    }
};

int main() {
    try {
        InventoryItem<int> item1(-5, 100);
    } catch (NegativeStockException &e) {
        cout << "Caught NegativeStockException - what(): " << e.what() << endl;
    }

    try {
        InventoryItem<int> item2(120, 100);
    } catch (OverCapacityException &e) {
        cout << "Caught OverCapacityException - what(): " << e.what() << endl;
    }

    return 0;
}
