#include <iostream>
#include <exception>
#include <string>
using namespace std;

    class DimensionMismatchException : public exception {
        string message;
    public:
        DimensionMismatchException(int r1, int c1, int r2, int c2) {
            message = "DimensionMismatchException - Matrices must have same dimensions ("
                    + to_string(r1) + "x" + to_string(c1) + " vs "
                    + to_string(r2) + "x" + to_string(c2) + ")!";
        }

        const char* what() const noexcept override {
            return message.c_str();
        }
    };

    template<typename T>
    class Matrix {
        int rows, cols;
        T values[10][10]; 
    public:
        Matrix(int r, int c, T v[][10]) : rows(r), cols(c) {
            for (int i = 0; i < rows; i++)
                for (int j = 0; j < cols; j++)
                    values[i][j] = v[i][j];
        }

        Matrix operator+(const Matrix& other) {
            if (rows != other.rows || cols != other.cols) {
                throw DimensionMismatchException(rows, cols, other.rows, other.cols);
            }

            T result[10][10];
            for (int i = 0; i < rows; i++)
                for (int j = 0; j < cols; j++)
                    result[i][j] = values[i][j] + other.values[i][j];

            return Matrix(rows, cols, result);
        }

        void display() const {
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++)
                    cout << values[i][j] << " ";
                cout << endl;
            }
        }
    };

int main() {
    try {
        int v1[10][10] = { {1, 2}, {3, 4} };
        int v2[10][10] = { {5, 6, 7}, {8, 9, 10}, {11, 12, 13} };

        Matrix<int> A(2, 2, v1);
        Matrix<int> B(3, 3, v2);

        Matrix<int> C = A + B;  
        C.display();
    }
    catch (const DimensionMismatchException& ex) {
        cout << ex.what() << endl;
    }

    return 0;
}
