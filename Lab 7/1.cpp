#include <string>
#include <iostream>
using namespace std;

class Device {
protected:
    string deviceID;
    string deviceName;
    bool status; 
    string location; 

public:
    Device(string id, string name, bool sta = false, string loc = "Unknown") 
        : deviceID(id), deviceName(name), status(sta), location(loc) {}

    virtual void turnOn() {
        status = true;
        cout << deviceName << " turned ON" << endl;
    }
    
    virtual void turnOff() {
        status = false;
        cout << deviceName << " turned OFF" << endl;
    }
    
    virtual string getStatus() const {
        return status ? "ON" : "OFF";
    }
    
    virtual void displayInfo() const {
        cout << "\nDevice Information:" << endl;
        cout << "ID: " << deviceID << endl;
        cout << "Name: " << deviceName << endl;
        cout << "Status: " << getStatus() << endl;
        cout << "Location: " << location << endl;
    }
};

class Light : public Device {
private:
    string colorMode;
    int brightnessLevel;

public:
    Light(string id, string name, bool sta = false, string loc = "Unknown", 
          string cm = "White", int bl = 50) 
        : Device(id, name, sta, loc), colorMode(cm), brightnessLevel(bl) {}

    void displayInfo() const override {
        Device::displayInfo();
        cout << "Color Mode: " << colorMode << endl;
        cout << "Brightness: " << brightnessLevel << "%" << endl;
    }
};

class Thermostat : public Device {
private:
    float currentTemperature;
    float targetTemperature;
    string mode; 

public:
    Thermostat(string id, string name, bool sta = false, string loc = "Unknown", 
               float ct = 20.0, float tt = 22.0, string m = "Cooling") 
        : Device(id, name, sta, loc), currentTemperature(ct), 
          targetTemperature(tt), mode(m) {}

    string getStatus() const override {
        string baseStatus = Device::getStatus();
        return baseStatus + " | Current Temp: " + to_string(currentTemperature) + 
               " | Mode: " + mode;
    }
};

class SecurityCamera : public Device {
private:
    string resolution;
    bool recordingStatus;
    bool nightVisionEnabled;

public:
    SecurityCamera(string id, string name, bool sta = false, string loc = "Unknown", 
                  string res = "1080p", bool n = false) 
        : Device(id, name, sta, loc), resolution(res), 
          nightVisionEnabled(n), recordingStatus(false) {}

    void turnOn() override {
        Device::turnOn();
        recordingStatus = true;
        cout << "Recording started (" << resolution << ")" << endl;
        if (nightVisionEnabled) {
            cout << "Night vision enabled" << endl;
        }
    }
    
};

class SmartPlug : public Device {
private:
    float powerConsumption;
    int timerSetting; 

public:
    SmartPlug(string id, string name, bool sta = false, string loc = "Unknown", 
              float p = 0.0, int ts = 0) 
        : Device(id, name, sta, loc), powerConsumption(p), timerSetting(ts) {}

    void turnOff() override {
        cout << "Power usage: " << powerConsumption << " kWh" << endl;
        Device::turnOff();
    }
};

int main() {
    Light livingRoomLight("L1", "Living Room Light", false, "Living Room", "Warm White", 75);
    Thermostat mainThermostat("T1", "Main Thermostat", true, "Hallway", 21.5, 22.0);
    SecurityCamera frontCamera("C1", "Front Camera", false, "Entrance", "4K", true);
    SmartPlug coffeeMaker("S1", "Coffee Maker", true, "Kitchen", 1.2);

    
    livingRoomLight.turnOn();
    cout<<endl;
    livingRoomLight.displayInfo();
    cout<<endl;
    
    cout << "\nThermostat Status: " << mainThermostat.getStatus() << endl;
    cout<<endl;
    
    frontCamera.turnOn();
    cout<<endl;
    frontCamera.displayInfo();
    cout<<endl;
    
    cout << "\nTurning off Coffee Maker:" << endl;
    coffeeMaker.turnOff();

    return 0;
}