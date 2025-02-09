#include <iostream>
using namespace std;

class FitnessTracker {
private:
    string userName;
    int dailyStepGoal;
    int stepsTaken;
    float caloriesBurned;

public:
    FitnessTracker(string name, int stepGoal) {
        userName = name;
        dailyStepGoal = stepGoal;
        stepsTaken = 0;
        caloriesBurned = 0;
    }

    void logSteps(int steps) {
        stepsTaken += steps;
        caloriesBurned += steps * 0.04;
    }

    void displayProgress() {
        cout << "\nFitness Progress\n";
        cout << "User: " << userName << endl;
        cout << "Daily Step Goal: " << dailyStepGoal << endl;
        cout << "Steps Taken: " << stepsTaken << endl;
        cout << "Calories Burned: " << caloriesBurned << " kcal\n";

        if (stepsTaken >= dailyStepGoal) {
            cout << " Goal Achieved! Keep it up!\n";
        } else {
            cout << " Keep going! " << (dailyStepGoal - stepsTaken) << " more steps to reach your goal.\n";
        }
    }
};

int main() {
    FitnessTracker tracker("Laiba", 10000);
    int choice, steps;

    while (true) {
        cout << "\n1. Log Steps\n";
        cout << "2. View Progress\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter steps taken: ";
                cin >> steps;
                tracker.logSteps(steps);
                break;
            case 2:
                tracker.displayProgress();
                break;
            case 3:
                cout << "Exiting\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}
