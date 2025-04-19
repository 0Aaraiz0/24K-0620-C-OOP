#include <iostream>
using namespace std;

class WeatherSensor {
public:
    virtual void readData() = 0;
    virtual void displayReport() = 0;
    virtual ~WeatherSensor() {}
};

class Thermometer : public WeatherSensor {
    double temperature;
public:
    void readData() {
        temperature = 22.5;  
    }

    void displayReport() {
        cout << "Temperature: " << temperature << " °C" << endl;
    }
};

class Barometer : public WeatherSensor {
    double pressure;
public:
    void readData() {
        pressure = 1012.0;  
    }

    void displayReport() {
        cout << "Pressure: " << pressure << " hPa" << endl;
    }
};

int main() {
    WeatherSensor* sensor1 = new Thermometer();
    WeatherSensor* sensor2 = new Barometer();

    sensor1->readData();
    sensor1->displayReport();

    sensor2->readData();
    sensor2->displayReport();

    delete sensor1;
    delete sensor2;

    return 0;
}
