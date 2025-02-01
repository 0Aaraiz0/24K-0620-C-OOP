#include <iostream>
using namespace std;

int main() {
    string days[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    string cities[4] = {"Lahore", "Karachi", "Islamabad", "Multan"};
    int AQI[4][7]; 
    float maxAQI = 0;
    int worstCityIndex = 0;
    int TAQI[4] = {0}; 
    float avgAQI[4];

    // Q1: Calculate average AQI and find the city with the worst air quality
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 7; j++) {
            cout << "Enter AQI of " << days[j] << " for " << cities[i] << ": ";
            cin >> AQI[i][j];
            TAQI[i] += AQI[i][j];
        }
    }

    
    cout << "\n--- Weekly AQI Averages ---\n";
    for (int i = 0; i < 4; i++) {
        avgAQI[i] = static_cast<float>(TAQI[i]) / 7;
        cout << cities[i] << ": " << avgAQI[i] << endl;
        
        if (avgAQI[i] > maxAQI) {
            maxAQI = avgAQI[i];
            worstCityIndex = i;
        }
    }
    cout << "\nCity with the worst air quality: " << cities[worstCityIndex] << " (AQI: " << maxAQI << ")\n";

    // Q2: Identify days where AQI exceeded 150
    cout << "\n--- Days with AQI Greater Than 150 ---\n";
    for (int i = 0; i < 4; i++) {
        cout << cities[i] << ": ";
        bool found = false;
        for (int j = 0; j < 7; j++) {
            if (AQI[i][j] > 150) {
                cout << days[j] << "  ";
                found = true;
            }
        }
        if (!found) {
            cout << "None";
        }
        cout << endl;
    }

    // Q3: Data Visualization
    cout << "\n--- AQI Data Visualization ---\n";
    for (int i = 0; i < 4; i++) {
        cout << cities[i] << ": ";
        for (int j = 0; j < 7; j++) {
            int stars = AQI[i][j] / 50; 
            for (int k = 0; k < stars; k++) {
                cout << "*";
            }
            cout << " ";
        }
        cout << endl;
    }

    // Q4: Monthly AQI Comparison
cout << "\n--- Monthly AQI Comparison ---\n";
int bestImprovementIndex = 0;
double maxImprovement = 0.0;

    for (int i = 0; i < 4; i++) {
    double firstWeekSum = 0, lastWeekSum = 0;

        for (int j = 0; j < 7; j++) {
        firstWeekSum += AQI[i][j];        
        lastWeekSum += AQI[i][j + 21];      
        }

    double firstWeekAvg = firstWeekSum / 7;
    double lastWeekAvg = lastWeekSum / 7;
    double improvement = firstWeekAvg - lastWeekAvg;

    if (improvement > maxImprovement) {
        maxImprovement = improvement;
        bestImprovementIndex = i;
    }
}

if (maxImprovement > 0) {
    cout << "City with most improved air quality: " << cities[bestImprovementIndex]
         << " (Largest drop in AQI: " << maxImprovement << ")\n";
} else {
    cout << "No significant improvement in air quality.\n";
}

    return 0;
}

