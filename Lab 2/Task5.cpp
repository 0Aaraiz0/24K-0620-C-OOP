#include <iostream>
using namespace std;

int main() {
    int num;
    
    cout << "Enter the number of elements: ";
    cin >> num;

    int* arr = new int[num];

    
    cout << "Enter " << num << " integers:\n";
    for (int i = 0; i < num; i++) {
        cin >> *(arr + i); 
    }

    cout << "\nArray elements: ";
    for (int i = 0; i < num; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;

    int sum = 0;
    int* ptr = arr;  
    for (int i = 0; i < num; i++) {
        sum += *(ptr + i); 
    }

    cout << "Sum of array elements: " << sum << endl;

    delete[] arr;

    return 0;
}
