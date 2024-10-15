#include <iostream>
using namespace std;

// Function overloading for different operations
int calculate(int a, int b, char op) {
    if (op == '+') return a + b;
    else if (op == '-') return a - b;
    else if (op == '*') return a * b;
    else if (op == '/') {
        if (b == 0) throw runtime_error("Division by zero!");
        return a / b;
    }
    throw invalid_argument("Invalid operator");
}

// Overloaded functions for double values
double calculate(double a, double b, char op) {
    if (op == '+') return a + b;
    else if (op == '-') return a - b;
    else if (op == '*') return a * b;
    else if (op == '/') {
        if (b == 0) throw runtime_error("Division by zero!");
        return a / b;
    }
    throw invalid_argument("Invalid operator");
}

int main() {
    try {
        int a, b;
        double x, y;
        char op;

        cout << "Enter two integers and an operator (+, -, *, /): ";
        cin >> a >> b >> op;
        cout << "Result: " << calculate(a, b, op) << endl;

        cout << "Enter two doubles and an operator (+, -, *, /): ";
        cin >> x >> y >> op;
        cout << "Result: " << calculate(x, y, op) << endl;

    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}

