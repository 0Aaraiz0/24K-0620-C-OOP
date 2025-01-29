#include <iostream>
using namespace std;

int main(){

    string days[7];
    string cities[4];
    int AQI[4][7];
    float max = 0;
    int TAQI[4];
    float avgAQI[4];
    int b;

    // Q1
    for(int i = 0 ; i < 4 ; i++)
    {
        for(int j = 0 ; j < 7 ; j ++)
        {
            cout<<"Enter AQI of"<<days[j]<<"of"<<cities[i]<<":  \n";
            cin>>AQI[i][j];
            TAQI[i]+=AQI[i][j];
        }
    }

    for(int i = 0 ; i < 4 ; i++)
    {
        avgAQI[i] = TAQI[i] / 7;
        if(avgAQI[i] > max)
        {
            max = avgAQI[i];
            b = i;
        }
        cout<<cities[i]<<"   "<<avgAQI[i];
    }
    cout<<"City with worst air : "<<cities[b];



    // Q2
    cout<<"Days with AQI greater than 150 \n";
    for(int i = 0 ; i < 4 ; i++)
    {   cout<<cities[i];
        for(int j = 0 ; j < 7 ; j++)
        {
            if(AQI[i][j] > 150)
            {
                cout<<days[j]<<"   ";
            }
        }
        cout<<"\n";
    }



    // Q3

     cout << "\n--- AQI Data Visualization ---\n";
    for (int i = 0; i < 4 ; i++) {
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


    
    // Q4
    cout << "\n--- Monthly AQI Comparison ---\n";
    int bestImprovementIndex = 0;
    double maxImprovement = 0.0;
    
    for (int i = 0; i < 4; i++) {
        double firstWeekSum = 0, lastWeekSum = 0;
        
        // Calculate first and last week averages
        for (int j = 0; j < 7; j++) {
            firstWeekSum += AQI[i][j];
            lastWeekSum += AQI[i][28 - j];
        }
        double firstWeekAvg = firstWeekSum / 7;
        double lastWeekAvg = lastWeekSum / 7;
        
        double improvement = firstWeekAvg - lastWeekAvg;
        if (improvement > maxImprovement) {
            maxImprovement = improvement;
            bestImprovementIndex = i;
        }
        }

    cout << "City with most improved air quality: " << cities[bestImprovementIndex] << " (Largest drop in AQI: " << maxImprovement << ")\n";

    return 0;
}
