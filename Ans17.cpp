#include <iostream>
using namespace std;

double divide(int a, int b) {
    if (b == 0) throw runtime_error("Division by zero!");
    return (double)a / b;
}

int main() {
    try {
        cout << divide(10, 0) << endl;
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}
