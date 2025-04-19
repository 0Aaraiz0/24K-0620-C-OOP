#include <iostream>
using namespace std;

class Patient {
protected:
    string name;
    string id;

public:
    Patient(string n, string i) : name(n), id(i) {}
    virtual ~Patient() {}

    virtual void displayTreatment() = 0;
    virtual double calculateCost() = 0;
};

class InPatient : public Patient {
private:
    int daysAdmitted;
    double dailyRate;

public:
    InPatient(string n, string i, int d, double r)
        : Patient(n, i), daysAdmitted(d), dailyRate(r) {}

    void displayTreatment() override {
        cout << "InPatient Treatment Details:\n";
        cout << "Name: " << name << ", ID: " << id << endl;
        cout << "Days Admitted: " << daysAdmitted 
             << ", Daily Rate: $" << dailyRate << endl;
    }

    double calculateCost() override {
        return daysAdmitted * dailyRate;
    }
};

class OutPatient : public Patient {
private:
    int numVisits;
    double costPerVisit;

public:
    OutPatient(string n, string i, int v, double c)
        : Patient(n, i), numVisits(v), costPerVisit(c) {}

    void displayTreatment() override {
        cout << "OutPatient Treatment Details:\n";
        cout << "Name: " << name << ", ID: " << id << endl;
        cout << "Visits: " << numVisits 
             << ", Cost per Visit: $" << costPerVisit << endl;
    }

    double calculateCost() override {
        return numVisits * costPerVisit;
    }
};

int main() {
    const int totalPatients = 2;

    Patient* patients[totalPatients];

    patients[0] = new InPatient("Ali Hassan", "IP123", 4, 300.0);
    patients[1] = new OutPatient("Bashir Khalil", "OP456", 2, 150.0);

    for (int i = 0; i < totalPatients; ++i) {
        patients[i]->displayTreatment();
        cout << "Total Treatment Cost: $" << patients[i]->calculateCost() << "\n\n";
    }

    for (int i = 0; i < totalPatients; ++i) {
        delete patients[i];
    }

    return 0;
}
