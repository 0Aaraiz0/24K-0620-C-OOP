#include <iostream>
using namespace std;

class AlarmSystem {
    string securityLevel;

public:
    AlarmSystem(string level) {
        securityLevel = level;
    }

    void display() {
        cout << "Alarm Security Level: " << securityLevel << endl;
    }
};

class SmartHome {
    string location;
    AlarmSystem alarm; 

public:
    SmartHome(string loc, string securityLevel) : alarm(securityLevel) {
        location = loc;
    }

    void displayDetails() {
        cout << "\nLocation: " << location << endl;
        alarm.display(); 
        cout << "---------------------------" << endl;
    }
};

int main() {

    SmartHome home1("Karachi", "High");
    SmartHome home2("Lahore", "Medium");

    home1.displayDetails();
    home2.displayDetails();

    return 0;
}
