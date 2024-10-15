#include <iostream>
using namespace std;

class A {
private:
    int value;
public:
    A(int v) : value(v) {}
    friend void displayValue(const A& a);
};

void displayValue(const A& a) {
    cout << "Value: " << a.value << endl;
}

int main() {
    A obj(42);
    displayValue(obj);
    return 0;
}
