#include <iostream>
using namespace std;

class Levels {
    string difficulty, name;

public:
    Levels() {} 
    Levels(string d, string n) : difficulty(d), name(n) {}

    void display() const {
        cout << "Difficulty: " << difficulty << ", Name: " << name << endl;
    }
};

class Game {
    string title, genre;
    Levels l1[10]; 
    int maxlevels;
    int levelcount;

public:
    Game(string t, string g, int mx) : title(t), genre(g), maxlevels(mx), levelcount(0) {}

    void addlevels(string d, string n) {
        if (levelcount < maxlevels) {
            l1[levelcount] = Levels(d, n); 
            levelcount++;
        } else {
            cout << "Not enough level slots!" << endl;
        }
    }

    void display() const {
        cout << "Title: " << title << endl;
        cout << "Genre: " << genre << endl;
        cout << "Levels:" << endl;
        for (int i = 0; i < levelcount; i++) {
            l1[i].display();
        }
    }
};

int main() {
    Game g("GTA", "Action", 10);

    g.addlevels("Hard", "Kaoi");
    g.addlevels("Easy", "Lamp");
    g.addlevels("Medium", "Poki");

    g.display();
    return 0;
}
