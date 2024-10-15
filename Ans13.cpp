#include <iostream>
using namespace std;

class Stack {
    int* arr;
    int top, capacity;

public:
    Stack(int size) : capacity(size), top(-1) {
        arr = new int[capacity];
    }

    void push(int x) {
        if (top == capacity - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return;
        }
        top--;
    }

    void display() const {
        for (int i = 0; i <= top; ++i)
            cout << arr[i] << " ";
        cout << endl;
    }

    ~Stack() { delete[] arr; }
};

int main() {
    Stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.display();
    s.pop();
    s.display();
    return 0;
}
