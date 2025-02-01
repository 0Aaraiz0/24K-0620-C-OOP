#include <iostream>

using namespace std;

int main() {
    int rows, cols;

    cout << "Enter the number of rows and columns: ";
    cin >> rows >> cols;

    int **A = new int*[rows];
    int **B = new int*[rows];
    int **multi = new int*[rows];

    for (int i = 0; i < rows; i++) {
        *(A + i) = new int[cols];
        *(B + i) = new int[cols];
        *(multi + i) = new int[cols];
    }

    cout << "Enter elements of Matrix A:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> *(*(A + i) + j);
        }
    }

    cout << "Enter elements of Matrix B:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> *(*(B + i) + j);
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            multi[i][j] = 0;
        }
    }


    for(int i = 0 ; i < rows ; i++)
    {
        for(int j = 0 ; j < cols; j++)
        {
            for(int k = 0 ; k < rows ; k++)
            {
                multi[i][j] += A[i][k] * B[k][j];            
            }
        }
    }

    cout << "\nMatrix Multiply:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << *(*(multi + i) + j) << " ";
        }
        cout << endl;
    }


    for (int i = 0; i < rows; i++) 
    {
        delete[] A[i];
        delete[] B[i];
        delete[] multi[i];
    }
    
    delete[] A;
    delete[] B;
    delete[] multi;

    return 0;
}