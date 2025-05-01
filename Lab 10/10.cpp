#include <iostream>
#include <fstream>
using namespace std;

int main() {

    ofstream outfile("data_records.txt");
    outfile << "Record 1\n";
    outfile << "Record 2\n";
    outfile << "Record 3\n";
    outfile << "Record 4\n";
    outfile.close();

    ifstream infile("data_records.txt", ios::binary); 

    if (!infile.is_open()) {
        cerr << "Error opening file.\n";
        return 1;
    }

    string line;

    infile.clear();
    infile.seekg(20, ios::beg);
    getline(infile, line);
    cout << "Line 3rd : "<<line<< endl;

    infile.close();
    return 0;
}

