#include <iostream>
#include <fstream>
#include <sstream> 
#include <string>
using namespace std;

int main() {
    ifstream in("vehicles.txt");  
    if (!in.is_open()) {
        cout << "File not opened" << endl;
        return 1;
    }

    string line;
    while (getline(in, line)) {
        if (line.empty() || line[0] == '#') {
            continue; 
        }

        istringstream iss(line);

        string type, id, name, year, extraData, certification;
        
        getline(iss, type, ',');
        getline(iss, id, ',');
        getline(iss, name, ',');
        getline(iss, year, ',');
        getline(iss, extraData, ',');
        getline(iss, certification, ',');

        cout << "Type: " << type << endl;
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        int year1 = stoi(year);
        cout << "Year: " << year1 << endl;
        cout << "ExtraData: " << extraData << endl;
        cout << "Certification: " << certification << endl;
        cout << "-----------------------------" << endl;

       if (type == "AutonomousCar") {
            size_t colonPos = extraData.find(':'); 
            if (colonPos != string::npos) {
                string versionStr = extraData.substr(colonPos + 1); 
                float softwareVersion = stof(versionStr); 
                cout << "ID: " << id << " | Software Version: " << softwareVersion << endl;
            }
        }
        else if (type == "ElectricVehicle") {
            size_t colonPos = extraData.find(':'); 
            if (colonPos != string::npos) {
                string batteryStr = extraData.substr(colonPos + 1);
                int batteryCapacity = stoi(batteryStr); 
                cout << "ID: " << id << " | Battery Capacity: " << batteryCapacity << endl;
            }
        }

       else if (type == "HybridTruck") {
            size_t CPos = extraData.find(':'); 
            size_t BPos = extraData.find('|');

        if (CPos != string::npos && BPos != string::npos) {
        string cargo1 = extraData.substr(CPos + 1, BPos - (CPos + 1));
        
        size_t batteryColon = extraData.find(':', BPos);
        string battery = extraData.substr(batteryColon + 1);
        
        int cargo2 = stoi(cargo1);
        int batteryCapacity = stoi(battery);

        cout << "ID: " << id 
             << " | Cargo: " << cargo2 
             << " | Battery Capacity: " << batteryCapacity 
             << endl;
    }
}
    }

    in.close();
    return 0;
}
