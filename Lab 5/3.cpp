#include <iostream>
using namespace std;

class Employee {
    string name, designation;

public:
    Employee(string n, string d) {
        name = n;
        designation = d;
    }

    void display() {
        cout << "Name: " << name << ", Designation: " << designation << endl;
    }
};

class Project {
    string title, deadline;
    Employee** employees;  
    int employeeCount;
    int capacity;

public:
    Project(string t, string d, int maxEmployees) {
        title = t;
        deadline = d;
        capacity = maxEmployees; 
        employeeCount = 0;
        employees = new Employee*[capacity]; 
    }

    void addEmployee(Employee* e) {
        if (employeeCount < capacity) {
            employees[employeeCount] = e;
            employeeCount++;
        } else {
            cout << "Cannot add more employees to " << title << ". Capacity full!\n";
        }
    }

    void displayDetails() {
        cout << "Project Title: " << title << "\nDeadline: " << deadline << "\nAssigned Employees:\n";
        if (employeeCount == 0) {
            cout << "No employees assigned yet.\n";
        } else {
            for (int i = 0; i < employeeCount; i++) {
                employees[i]->display();
            }
        }
        cout << "------------------------\n";
    }

    ~Project() {
        delete[] employees;
    }
};

int main() {
    Employee* e1 = new Employee("Ali", "Software Engineer");
    Employee* e2 = new Employee("Sara", "Project Manager");
    Employee* e3 = new Employee("Ahmed", "QA Engineer");

    Project p1("AI Development", "2025-05-30", 2);
    Project p2("Web Application", "2025-06-15", 2);

    p1.addEmployee(e1);
    p1.addEmployee(e2);
    
    p2.addEmployee(e2);
    p2.addEmployee(e3);

    cout << "Project Details:\n";
    p1.displayDetails();
    p2.displayDetails();

    delete e1;
    delete e2;
    delete e3;

    return 0;
}
