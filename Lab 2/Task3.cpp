#include <iostream>
using namespace std;

struct Employee {
    string name;
    int hoursWorked;
    double hourlyRate;
};

int main() {
    int num;
    
    cout << "Enter number of employees: ";
    cin >> num;

    Employee *employees = new Employee[num];

    for (int i = 0; i < num; i++) {
        cout << "\nEmployee " << i + 1<<endl<<endl;
        cout << "Name: "<<endl;
        cin >> employees[i].name;
        cout << "Hours Worked: "<<endl;
        cin >> employees[i].hoursWorked;
        cout << "Hourly Rate: "<<endl;
        cin >> employees[i].hourlyRate;
    }

    cout << "\nEmployee Salaries:\n";
    for (int i = 0; i < num; i++) {
        double salary = employees[i].hoursWorked * employees[i].hourlyRate;
        cout << employees[i].name << ": $" << salary << endl;
    }

    delete[] employees;

    return 0;
}
