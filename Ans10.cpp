#include <iostream>
using namespace std;

class Matrix {
    int rows, cols;
    int** data;

public:
    Matrix(int r, int c) : rows(r), cols(c) {
        data = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols];
        }
    }

    void input() {
        cout << "Enter matrix elements:\n";
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                cin >> data[i][j];
    }

    Matrix operator+(const Matrix& m) {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                result.data[i][j] = data[i][j] + m.data[i][j];
        return result;
    }

    Matrix operator*(const Matrix& m) {
        Matrix result(rows, m.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < m.cols; ++j) {
                result.data[i][j] = 0;
                for (int k = 0; k < cols; ++k) {
                    result.data[i][j] += data[i][k] * m.data[k][j];
                }
            }
        }
        return result;
    }

    void display() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j)
                cout << data[i][j] << " ";
            cout << endl;
        }
    }

    ~Matrix() {
        for (int i = 0; i < rows; ++i)
            delete[] data[i];
        delete[] data;
    }
};

int main() {
    Matrix m1(2, 2), m2(2, 2);
    m1.input();
    m2.input();

    Matrix sum = m1 + m2;
    Matrix product = m1 * m2;

    cout << "Sum:\n";
    sum.display();
    cout << "Product:\n";
    product.display();
    return 0;
}
