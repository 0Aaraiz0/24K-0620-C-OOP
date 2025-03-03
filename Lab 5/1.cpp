#include <iostream>
using namespace std;

class Apartment {
    int ID;
    string address;
    string *ownerName;

public:
    Apartment(int i, string a, string *o) {
        ID = i;
        address = a;
        ownerName = new string(*o); 
    }

    Apartment(const Apartment &obj) {
        ID = obj.ID;
        address = obj.address;
        ownerName = new string(*obj.ownerName);
    }
    void updateownername(string a){
        *ownerName = a;
    }

    ~Apartment() {
        delete ownerName;
    }

    void display() {
        cout << "ID: " << ID << endl;
        cout << "Address: " << address << endl;
        cout << "Owner Name: " << *ownerName << endl;
    }
};

int main() {
    string owner1 = "Kamran";
    string owner2 = "Ali";
    string owner3 = "Sara";

    Apartment a1(187, "Street #18, 17th Avenue", &owner1);
    Apartment a2(102, "Block C, City Center", &owner2);
    Apartment a3(309, "Main Road, Green Town", &owner3);

    Apartment a4(a1);

    cout << "Original Apartments:\n";
    a1.display();
    cout << endl;
    a2.display();
    cout << endl;
    a3.display();
    cout << "\nCopied Apartment (a4 from a1):\n";
    a4.display();
    a1.updateownername("Kara");
    cout<<"a1 after update:"<<endl;
    a1.display();
    cout<<"a4 after updating a1"<<endl;
    a4.display();

    return 0;
}
