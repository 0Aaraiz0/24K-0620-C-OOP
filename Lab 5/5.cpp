#include <iostream>

using namespace std;

class Doctor {
    string name, specialization, experience;

public:
    Doctor(string n, string s, string e) {
        name = n;
        specialization = s;
        experience = e;
    }

    void displayDetails() {
        cout << "Name: " << name << endl;
        cout << "Specialization: " << specialization << endl;
        cout << "Experience: " << experience << " years" << endl;
    }
};

class Hospital {
    string name, location;
    Doctor** doctors;  
    int maxDoctors;
    int doctorCount;

public:
    Hospital(string n, string l, int maxD) {
        name = n;
        location = l;
        maxDoctors = maxD;
        doctorCount = 0;
        doctors = new Doctor*[maxDoctors]; 
    }

    void addDoctor(Doctor* d) {
        if (doctorCount < maxDoctors) {
            doctors[doctorCount] = d;
            doctorCount++;
        } else {
            cout << "Hospital is full, cannot add more doctors!" << endl;
        }
    }

    void displayDetails() {
        cout << "Hospital Name: " << name << endl;
        cout << "Location: " << location << endl;
        cout << "Doctors List: " << endl;
        for (int i = 0; i < doctorCount; i++) {
            doctors[i]->displayDetails();
            cout << "----------------------" << endl;
        }
    }

    ~Hospital() {
        delete[] doctors;  
    }
};

int main() {
    Doctor* d1 = new Doctor("Dr. Ali", "Cardiologist", "10");
    Doctor* d2 = new Doctor("Dr. Sara", "Neurologist", "7");
    Doctor* d3 = new Doctor("Dr. Ahmed", "Orthopedic", "5");

    Hospital h("City Hospital", "Lahore", 5);

    h.addDoctor(d1);
    h.addDoctor(d2);
    h.addDoctor(d3);

    h.displayDetails();

    delete d1;
    delete d2;
    delete d3;

    return 0;
}
