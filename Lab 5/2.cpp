#include <iostream>
using namespace std;

class Student {
private:
    int ID;
    string name;
    int *scores;
    int numScores;

public:
    Student(int id, string n, int *sc, int num) {
        ID = id;
        name = n;
        numScores = num;
        scores = new int[numScores]; 

        for (int i = 0; i < numScores; i++) {
            scores[i] = sc[i]; 
        }
    }

    Student(Student &obj) {
        ID = obj.ID;
        name = obj.name;
        numScores = obj.numScores;
        scores = new int[numScores];

        for (int i = 0; i < numScores; i++) {
            scores[i] = obj.scores[i]; 
        }
    }

    ~Student() {
        delete[] scores;
    }

    void display() {
        cout << "ID: " << ID << "\nName: " << name << "\nScores: ";
        for (int i = 0; i < numScores; i++) {
            cout << scores[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    int scores1[] = {85, 90, 78}; 
    int scores2[] = {88, 76, 92};

    Student s1(101, "Ali", scores1, 3);
    Student s2(102, "Sara", scores2, 3);

    Student s3(s1);

    cout << "Original Student Records:\n";
    s1.display();
    s2.display();

    cout << "\nCopied Student Record\n";
    s3.display();

    return 0;
}
