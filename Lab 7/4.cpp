#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int age;
    string contactNumber;
    string address;

public:
    Person(string n, int a, string contact, string addr = "")
        : name(n), age(a), contactNumber(contact), address(addr) {}

    virtual void displayInfo() {
        cout << "Name: " << name << "\nAge: " << age << "\nContact: " << contactNumber << "\nAddress: " << address << "\n";
    }
    virtual void updateInfo(string newContact, string newAddress) {
        contactNumber = newContact;
        address = newAddress;
    }
};

class Patient : public Person {
private:
    int patientID;
    string medicalHistory;
    string doctorAssigned;

public:
    Patient(string n, int a, string contact, int id, string history, string doctor)
        : Person(n, a, contact), patientID(id), medicalHistory(history), doctorAssigned(doctor) {}

    void displayInfo() override {
        Person::displayInfo();
        cout << "Patient ID: " << patientID << "\nMedical History: " << medicalHistory << "\nDoctor Assigned: " << doctorAssigned << "\n";
    }
};

class Doctor : public Person {
private:
    string specialization;
    double consultationFee;
    Patient* patientsList[5]; 

public:
    Doctor(string n, int a, string contact, string spec, double fee, Patient* patients[])
        : Person(n, a, contact), specialization(spec), consultationFee(fee) {
        for (int i = 0; i < 5; i++) patientsList[i] = patients[i];
    }

    void displayInfo() override {
        Person::displayInfo();
        cout << "Specialization: " << specialization << "\nConsultation Fee: Rs." << consultationFee << "\nPatients:\n";
        for (int i = 0; i < 5; i++) {
            if (patientsList[i]) {
                patientsList[i]->displayInfo();
                cout << "-------------------\n";
            }
        }
    }
};

class Nurse : public Person {
private:
    string assignedWard;
    string shiftTimings;

public:
    Nurse(string n, int a, string contact, string ward, string shift)
        : Person(n, a, contact), assignedWard(ward), shiftTimings(shift) {}

    void displayInfo() override {
        Person::displayInfo();
        cout << "Assigned Ward: " << assignedWard << "\nShift Timings: " << shiftTimings << "\n";
    }
};

class Administrator : public Person {
private:
    string department;
    double salary;

public:
    Administrator(string n, int a, string contact, string dept, double sal)
        : Person(n, a, contact), department(dept), salary(sal) {}

    void updateInfo(string newContact, string newAddress, double newSalary) {
        Person::updateInfo(newContact, newAddress);
        salary = newSalary;
    }

    void displayInfo() override {
        Person::displayInfo();
        cout << "Department: " << department << "\nSalary: Rs." << salary << "\n";
    }
};

int main() {
    Patient p1("Hassan", 30, "0312-1234567", 101, "Diabetes", "Dr. Khan");
    Patient p2("Ali", 40, "0313-2345678", 102, "Hypertension", "Dr. Khan");
    Patient p3("Ahmed", 35, "0314-3456789", 103, "Asthma", "Dr. Khan");
    Patient p4("Sara", 28, "0315-4567890", 104, "Allergies", "Dr. Khan");
    Patient p5("Fatima", 50, "0316-5678901", 105, "Arthritis", "Dr. Khan");

    Patient* patients[] = {&p1, &p2, &p3, &p4, &p5};
    Doctor d1("Dr. Khan", 45, "0300-7654321", "Cardiology", 2500.0, patients);
    Nurse n1("Ayesha", 28, "0333-9876543", "ICU", "Night Shift");
    Administrator a1("Mr. Akbar", 50, "0321-4567890", "HR", 80000.0);

    cout << "--- Doctor Info ---\n";
    d1.displayInfo();
    cout << "-------------------\n";

    cout << "--- Nurse Info ---\n";
    n1.displayInfo();
    cout << "-------------------\n";

    cout << "--- Administrator Info ---\n";
    a1.displayInfo();
    cout << "-------------------\n";

    return 0;
}
