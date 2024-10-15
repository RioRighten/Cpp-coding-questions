#include <iostream>
using namespace std;

class Calculator {
public:
    int calculate(int a, int b) { return a + b; }
    int calculate(int a, int b, char op) {
        switch (op) {
            case '-': return a - b;
            case '*': return a * b;
            case '/': return b != 0 ? a / b : 0;
            default: return 0;
        }
    }
};

int main() {
    Calculator calc;
    cout << "Addition: " << calc.calculate(10, 5) << endl;
    cout << "Multiplication: " << calc.calculate(10, 5, '*') << endl;
    return 0;
}
