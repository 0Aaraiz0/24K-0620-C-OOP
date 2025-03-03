#include <iostream>
using namespace std;

class Person { 
protected:
    string name;
    int age;

public:
    Person(string n, int a) {
        name = n;
        age = a;
    }

    virtual void displayDetails() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Teacher : virtual public Person { 
protected:
    string subject;

public:
    Teacher(string n, int a, string sub) : Person(n, a) {
        subject = sub;
    }

    void displayDetails() override {
        Person::displayDetails();
        cout << "Subject Expertise: " << subject << endl;
    }
};

class Researcher : virtual public Person { 
protected:
    string researchArea;

public:
    Researcher(string n, int a, string rArea) : Person(n, a) {
        researchArea = rArea;
    }

    void displayDetails() override {
        Person::displayDetails();
        cout << "Research Area: " << researchArea << endl;
    }
};

class Professor : public Teacher, public Researcher { 
    int publications;

public:
    Professor(string n, int a, string sub, string rArea, int pubs)
        : Person(n, a), Teacher(n, a, sub), Researcher(n, a, rArea) {
        publications = pubs;
    }

    void displayDetails() override {
        Person::displayDetails();
        cout << "Subject Expertise: " << subject << endl;
        cout << "Publications: " << publications << endl;
    }
};

int main() {
    string name, subject, researchArea;
    int age, publications;

    cout << "Enter name: ";
    cin >> name;
    cout << "Enter age: ";
    cin >> age;
    cout << "Enter subject expertise: ";
    cin >> subject;
    cout << "Enter research area: ";
    cin >> researchArea;
    cout << "Enter number of publications: ";
    cin >> publications;

    Professor prof(name, age, subject, researchArea, publications);

    cout << "\nProfessor Details:\n";
    prof.displayDetails(); 

    return 0;
}
