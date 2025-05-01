#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream outFile("config.txt");
    outFile << "AAAAA" << "BBBBB" << "CCCCC";  
    outFile.close();

    fstream file("config.txt", ios::in | ios::out);

    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    file.seekp(5);  

    file << "XXXXX";

    file.close();

    ifstream inFile("config.txt");
    string updatedContent;
    getline(inFile, updatedContent);
    cout << "Updated file content: " << updatedContent << endl;

    inFile.close();
    return 0;
}
