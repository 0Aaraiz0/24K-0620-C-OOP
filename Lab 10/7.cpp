#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream out("sensor_log.txt");

    if (!out.is_open()) {
        cout << "Failed to open file." << endl;
        return 1;
    }

    string sensorData1 = "Temperature: 25.4 C\n";
    string sensorData2 = "Humidity: 60%\n";
    string sensorData3 = "Pressure: 101.3 kPa\n";

    out << sensorData1;
    cout << "Position after writing 1st line: " << out.tellp() << endl;

    out << sensorData2;
    cout << "Position after writing 2nd line: " << out.tellp() << endl;

    out << sensorData3;
    cout << "Position after writing 3rd line: " << out.tellp() << endl;

    out.close();
    return 0;
}
