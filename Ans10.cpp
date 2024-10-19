#include <iostream>
using namespace std;

class Matrix {
private:
    int rows, cols;
    int** data;

public:
    // Constructor to initialize matrix with given dimensions
    Matrix(int r, int c) : rows(r), cols(c) {
        data = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols];
        }
    }

    // Destructor to free dynamically allocated memory
    ~Matrix() {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    // Method to input matrix elements
    void input() {
        cout << "Enter elements of the matrix (" << rows << "x" << cols << "):\n";
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cin >> data[i][j];
            }
        }
    }

    // Overload + operator for matrix addition
    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw invalid_argument("Matrices must have the same dimensions for addition.");
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    // Overload * operator for matrix multiplication
    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows) {
            throw invalid_argument("Number of columns in first matrix must match rows in second.");
        }
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                result.data[i][j] = 0;
                for (int k = 0; k < cols; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    // Method to display the matrix
    void display() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int r1, c1, r2, c2;

    cout << "Enter dimensions of first matrix (rows cols): ";
    cin >> r1 >> c1;
    Matrix mat1(r1, c1);
    mat1.input();

    cout << "Enter dimensions of second matrix (rows cols): ";
    cin >> r2 >> c2;
    Matrix mat2(r2, c2);
    mat2.input();

    try {
        if (r1 == r2 && c1 == c2) {
            Matrix sum = mat1 + mat2;
            cout << "Sum of matrices:\n";
            sum.display();
        } else {
            cout << "Matrices can't be added due to different dimensions.\n";
        }

        if (c1 == r2) {
            Matrix product = mat1 * mat2;
            cout << "Product of matrices:\n";
            product.display();
        } else {
            cout << "Matrices can't be multiplied due to incompatible dimensions.\n";
        }
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
