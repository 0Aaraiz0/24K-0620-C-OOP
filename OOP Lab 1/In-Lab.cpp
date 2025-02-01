#include <iostream>
using namespace std;

int main() {
    
    string event1[5];
    string event2[5];
    string find;
    int a = 0;
    int b = -1; 
    int amount = 0;

    // Q1
    for(int i = 0; i < 5; i++) {
        cout << "Write name of person " << i + 1 << " for Event 1: ";
        cin >> event1[i];
        amount += 10; //Q3
    }

    for(int i = 0; i < 5; i++) {
        cout << "Write name of person " << i + 1 << " for Event 2: ";
        cin >> event2[i]; 
        amount += 10; //Q3
    }

    // Q2
    cout << "Enter name of person to find: ";
    cin >> find;

    for(int i = 0; i < 5; i++) {
        if(find == event1[i] || find == event2[i]) {
            a++;
            b = i + 1; 
        }
    }

    if(a != 0) {
        cout << "Person found at position " << b << endl;
    } else {
        cout << "Person not found." << endl;
    }

    // Q4
    cout << endl << "Event 1 Participants:" << endl;
    for(int i = 4; i >= 0; i--) {
        cout << "Participant " << i + 1 << ": " << event1[i] << endl;
    }

    cout << endl << "Event 2 Participants:" << endl;
    for(int i = 4; i >= 0; i--) {
        cout << "Participant " << i + 1 << ": " << event2[i] << endl;
    }

    // Q5
    cout << endl << "       BAR CHART      " << endl;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 16; j++) {
            if(j == 4 || j == 13) {
                cout << "*";
            } else {
                cout << " "; 
            }
        }
        cout << endl;
    }

    cout << "Event 1    Event 2" << endl;

    return 0;
}

