#include <iostream>
using namespace std;

class MenuItem {
protected:
    string dishName;
    double price;

public:
    MenuItem(string name_, double price_) : dishName(name_), price(price_) {}
    virtual ~MenuItem() {}

    virtual void showDetails() = 0;
    virtual void prepare() = 0;
};

class Appetizer : public MenuItem {
public:
    Appetizer(string name_, double price_) : MenuItem(name_, price_) {}

    void showDetails() override {
        cout << "Appetizer: " << dishName << " | Price: $" << price << endl;
    }

    void prepare() override {
        cout << "Preparing appetizer: " << dishName << "\n"
             << "- Washing and chopping ingredients\n"
             << "- Light cooking or seasoning\n"
             << "- Plating neatly\n";
    }
};

class MainCourse : public MenuItem {
public:
    MainCourse(string name_, double price_) : MenuItem(name_, price_) {}

    void showDetails() override {
        cout << "Main Course: " << dishName << " | Price: $" << price << endl;
    }

    void prepare() override {
        cout << "Preparing main course: " << dishName << "\n"
             << "- Marinating ingredients\n"
             << "- Full cooking process (grilling/boiling/etc)\n"
             << "- Sides preparation\n"
             << "- Plating\n";
    }
};

int main() {
    const int menuSize = 2;
    MenuItem* menu[menuSize];

    menu[0] = new Appetizer("Cheese sticks", 6.50);
    menu[1] = new MainCourse("Roast", 14.99);

    for (int i = 0; i < menuSize; ++i) {
        menu[i]->showDetails();
        menu[i]->prepare();
        cout << endl;
    }

    for (int i = 0; i < menuSize; ++i) {
        delete menu[i];
    }

    return 0;
}
