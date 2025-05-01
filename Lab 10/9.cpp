#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream outfile("large_log.txt");
    outfile << "This is the first part of the log file. It contains important logs.";
    outfile.close();

    ifstream infile("large_log.txt", ios::in);
    if (!infile) {
        cerr << "File could not be opened!" << endl;
        return 1;
    }

    char buffer1[11]; 
    infile.read(buffer1, 10);
    buffer1[10] = '\0';
    cout << "First 10 characters: \"" << buffer1 << "\"" << endl;
    cout << "Position after first read: " << infile.tellg() << endl;

    char buffer2[11];
    infile.read(buffer2, 10);
    buffer2[10] = '\0';
    cout << "Next 10 characters: \"" << buffer2 << "\"" << endl;
    cout << "Position after second read: " << infile.tellg() << endl;

    infile.close();
    return 0;
}
