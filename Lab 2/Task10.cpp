#include <iostream>

using namespace std;

int main() {
    int x, y, z;

    cout << "Enter dimensions (x y z): ";
    cin >> x >> y >> z;

    int*** array = new int**[x];
    for (int i = 0; i < x; i++) {
        array[i] = new int*[y];
        for (int j = 0; j < y; j++) {
            array[i][j] = new int[z];
        }
    }

    cout << "Enter " << x * y * z << " elements:" << endl;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                cin >> array[i][j][k];
            }
        }
    }

    cout << "3D Array:" << endl;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                cout << array[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            delete[] array[i][j];
        }
        delete[] array[i];
    }
    delete[] array;

    return 0;
}
