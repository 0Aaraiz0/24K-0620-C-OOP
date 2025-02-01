#include <iostream>
using namespace std;

int main() {
    int num;

    cout << "Enter the number of strings: ";
    cin >> num;

    string* words = new string[num];

    for (int i = 0; i < num; i++) {
        cout << "Enter string " << i + 1 << ": ";
        cin >> words[i]; 
    }

    for(int i = 0 ; i < num ; i++) {
        int len = words[i].length(); 
        for(int j = 0 ; j < len - 1 ; j++) {
            for(int k = j+1 ; k < len ; k++) {
                if(words[i][j] > words[i][k]) {
                    char temp = words[i][j];
                    words[i][j] = words[i][k];
                    words[i][k] = temp;
                }
            }
        }
    }

    cout << "\nSorted Strings:\n";
    for (int i = 0; i < num; i++) {
        cout << words[i] << endl;
    }

    delete[] words;

    return 0;
}
