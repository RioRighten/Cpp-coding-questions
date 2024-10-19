#include <iostream>
using namespace std;

// Template function to swap two values
template <typename T>
void swapValues(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 5, y = 10;
    double m = 1.5, n = 3.7;
    char c1 = 'A', c2 = 'B';

    cout << "Before Swap:" << endl;
    cout << "x = " << x << ", y = " << y << endl;
    cout << "m = " << m << ", n = " << n << endl;
    cout << "c1 = " << c1 << ", c2 = " << c2 << endl;

    // Swapping integers
    swapValues(x, y);
    // Swapping doubles
    swapValues(m, n);
    // Swapping characters
    swapValues(c1, c2);

    cout << "\nAfter Swap:" << endl;
    cout << "x = " << x << ", y = " << y << endl;
    cout << "m = " << m << ", n = " << n << endl;
    cout << "c1 = " << c1 << ", c2 = " << c2 << endl;

    return 0;
}
