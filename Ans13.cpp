#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;      // Array to hold stack elements
    int top;       // Index of the top element
    int capacity;  // Maximum number of elements in the stack

public:
    // Constructor to initialize the stack
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;  // Stack is initially empty
    }

    // Destructor to free memory
    ~Stack() {
        delete[] arr;
    }

    // Method to add an item to the stack
    void push(int item) {
        if (top == capacity - 1) {
            cout << "Stack Overflow! Unable to push " << item << endl;
            return;
        }
        arr[++top] = item;  // Increment top and add item
        cout << item << " pushed to stack." << endl;
    }

    // Method to remove an item from the stack
    int pop() {
        if (top == -1) {
            cout << "Stack Underflow! Unable to pop." << endl;
            return -1;  // Return -1 if stack is empty
        }
        return arr[top--];  // Return top item and decrement top
    }

    // Method to display the stack elements
    void display() {
        if (top == -1) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; --i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size;

    cout << "Enter the size of the stack: ";
    cin >> size;
    
    Stack stack(size);  // Create a stack of given size

    // Performing stack operations
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.display();

    cout << "Popped item: " << stack.pop() << endl;
    stack.display();

    stack.push(40);
    stack.push(50);
    stack.display();

    // Attempting to pop all elements
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();  // This will show underflow message

    return 0;
}
