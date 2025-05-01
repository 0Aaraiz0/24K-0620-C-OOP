#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class InventoryItem {
public:
    int itemID;
    char itemName[20];

    InventoryItem(int id = 0, const char* name = "") {
        itemID = id;
        strncpy(itemName, name, 19);
        itemName[19] = '\0'; 
    }

    void save() {
        ofstream out("inventory.dat", ios::binary);
        out.write((char*)this, sizeof(*this));
        out.close();
    }

    void load() {
        ifstream in("inventory.dat", ios::binary);
        in.read((char*)this, sizeof(*this));
        in.close();
    }

    void print() {
        cout << "ID: " << itemID << ", Name: " << itemName << endl;
    }
};

int main() {    
    InventoryItem item1(123, "Wrench");
    item1.save();

    InventoryItem item2;
    item2.load();
    item2.print();

    return 0;
}
