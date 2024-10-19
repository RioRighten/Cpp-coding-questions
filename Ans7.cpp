#include <iostream>
using namespace std;

class B;  // Forward declaration of class B

class A {
private:
    int valueA;

public:
    A(int val) : valueA(val) {}

    friend void showValues(const A& objA, const B& objB);  // Friend function declaration
};

class B {
private:
    int valueB;

public:
    B(int val) : valueB(val) {}

    friend void showValues(const A& objA, const B& objB);  // Friend function declaration
};

// Friend function definition
void showValues(const A& objA, const B& objB) {
    cout << "Value from class A: " << objA.valueA << endl;
    cout << "Value from class B: " << objB.valueB << endl;
}

int main() {
    A objA(10);  // Create an object of class A with value 10
    B objB(20);  // Create an object of class B with value 20

    showValues(objA, objB);  // Call the friend function

    return 0;
}
