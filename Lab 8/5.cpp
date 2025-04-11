#include <iostream>
using namespace std;

class MatrixHelper; 

class Matrix {
private:
    int m[2][2];

public:
    Matrix(int a = 0, int b = 0, int c = 0, int d = 0) {
        m[0][0] = a; m[0][1] = b;
        m[1][0] = c; m[1][1] = d;
    }

    Matrix operator+(const Matrix& other) const {
        return Matrix(
            m[0][0] + other.m[0][0], m[0][1] + other.m[0][1],
            m[1][0] + other.m[1][0], m[1][1] + other.m[1][1]
        );
    }

    Matrix operator-(const Matrix& other) const {
        return Matrix(
            m[0][0] - other.m[0][0], m[0][1] - other.m[0][1],
            m[1][0] - other.m[1][0], m[1][1] - other.m[1][1]
        );
    }

    Matrix operator*(const Matrix& other) const {
        return Matrix(
            m[0][0]*other.m[0][0] + m[0][1]*other.m[1][0],
            m[0][0]*other.m[0][1] + m[0][1]*other.m[1][1],
            m[1][0]*other.m[0][0] + m[1][1]*other.m[1][0],
            m[1][0]*other.m[0][1] + m[1][1]*other.m[1][1]
        );
    }

    friend int determinant(const Matrix& mat);

    friend class MatrixHelper;

    friend ostream& operator<<(ostream& os, const Matrix& mat);
};

int determinant(const Matrix& mat) {
    return mat.m[0][0] * mat.m[1][1] - mat.m[0][1] * mat.m[1][0];
}

ostream& operator<<(ostream& os, const Matrix& mat) {
    os << "[ " << mat.m[0][0] << " " << mat.m[0][1] << " ]\n";
    os << "[ " << mat.m[1][0] << " " << mat.m[1][1] << " ]";
    return os;
}

class MatrixHelper {
public:
    void updateElement(Matrix& mat, int row, int col, int value) {
        if (row >= 0 && row < 2 && col >= 0 && col < 2) {
            mat.m[row][col] = value;
            cout << "Updated element at (" << row << "," << col << ") to " << value << "\n";
        } else {
            cout << "Invalid index.\n";
        }
    }
};

int main() {
    Matrix A(1, 2, 3, 4);
    Matrix B(5, 6, 7, 8);

    cout << "Matrix A:\n" << A << "\n";
    cout << "Matrix B:\n" << B << "\n";

    Matrix sum = A + B;
    Matrix diff = A - B;
    Matrix prod = A * B;

    cout << "\nA + B:\n" << sum << "\n";
    cout << "\nA - B:\n" << diff << "\n";
    cout << "\nA * B:\n" << prod << "\n";

    cout << "\nDeterminant of A: " << determinant(A) << "\n";

    MatrixHelper helper;
    helper.updateElement(A, 0, 1, 10);  
    cout << "Matrix A after update:\n" << A << "\n";

    return 0;
}
