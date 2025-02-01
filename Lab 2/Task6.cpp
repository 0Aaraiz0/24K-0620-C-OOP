#include <iostream>
using namespace std;

struct Student {
    string name;
    int rollNumber;
    float marks[3];
};

int main() {
    int num;
    cout << "Enter the number of students: ";
    cin >> num;

    Student* students = new Student[num];

    for (int i = 0; i < num; i++) {
        cout << "\nEnter details for Student " << i + 1 << ":\n";
        cout << "Name: "<<endl;
        cin >>students[i].name;
        cout << "Roll Number: "<<endl;
        cin >> students[i].rollNumber;
        cout << "Enter marks in 3 subjects: "<<endl;
        for (int j = 0; j < 3; j++) {
            cin >> students[i].marks[j];
        }
    }

    cout << "\n---------------------------\n";
    cout << "Name\tRoll No\tAvg Marks\n";
    cout << "---------------------------\n";

    for (int i = 0; i < num; i++) {
        float sum = 0;
        for (int j = 0; j < 3; j++) {
            sum += students[i].marks[j];
        }
        cout << students[i].name << "\t" << students[i].rollNumber << "\t" << (sum / 3) << endl;
    }

    delete[] students;
    return 0;
}
