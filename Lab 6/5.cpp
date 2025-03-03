#include <iostream>
using namespace std;

class Device {
protected:
    int deviceID;
    bool status;

public:
    Device(int id, bool st) {
        deviceID = id;
        status = st;
    }

    virtual void displayDetails() {
        cout << "Device ID: " << deviceID << endl;
        cout << "Status: " << (status ? "On" : "Off") << endl;
    }
};

class SmartPhone : virtual public Device {
protected:
    float screenSize;

public:
    SmartPhone(int id, bool st, float ss) : Device(id, st) {
        screenSize = ss;
    }

    void displayDetails() override {
        Device::displayDetails();
        cout << "Screen Size: " << screenSize << " inches" << endl;
    }
};

class SmartWatch : virtual public Device {
protected:
    bool heartRateMonitor;

public:
    SmartWatch(int id, bool st, bool hrm) : Device(id, st) {
        heartRateMonitor = hrm;
    }

    void displayDetails() override {
        Device::displayDetails();
        cout << "Heart Rate Monitor: " << (heartRateMonitor ? "Enabled" : "Disabled") << endl;
    }
};

class SmartWearable : public SmartPhone, public SmartWatch {
    int stepCounter;

public:
    SmartWearable(int id, bool st, float ss, bool hrm, int sc) 
        : Device(id, st), SmartPhone(id, st, ss), SmartWatch(id, st, hrm) {
        stepCounter = sc;
    }

    void displayDetails() override {
        Device::displayDetails();
        cout << "Screen Size: " << screenSize << " inches" << endl;
        cout << "Heart Rate Monitor: " << (heartRateMonitor ? "Enabled" : "Disabled") << endl;
        cout << "Step Counter: " << stepCounter << " steps" << endl;
    }
};

int main() {
    int id, steps;
    bool status, hrm;
    float screenSize;

    cout << "Enter Smart Wearable Specifications:\n";
    cout << "Device ID: ";
    cin >> id;
    cout << "Status (1 for On, 0 for Off): ";
    cin >> status;
    cout << "Screen Size (in inches): ";
    cin >> screenSize;
    cout << "Heart Rate Monitor (1 for Enabled, 0 for Disabled): ";
    cin >> hrm;
    cout << "Step Counter: ";
    cin >> steps;

    SmartWearable wearable(id, status, screenSize, hrm, steps);

    cout << "\nSmart Wearable Details:\n";
    wearable.displayDetails();

    return 0;
}
