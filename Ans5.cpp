#include <iostream>
using namespace std;

// Abstract class Animal with a pure virtual function
class Animal {
public:
    // Pure virtual function
    virtual void makeSound() const = 0;  
};

// Derived class Cat that overrides makeSound()
class Cat : public Animal {
public:
    void makeSound() const override {
        cout << "Cat: Meow!" << endl;
    }
};

// Derived class Dog that overrides makeSound()
class Dog : public Animal {
public:
    void makeSound() const override {
        cout << "Dog: Woof!" << endl;
    }
};

int main() {
    // Using base class pointers to demonstrate polymorphism
    Animal* animal1 = new Cat();
    Animal* animal2 = new Dog();

    // Calling the overridden functions through base class pointers
    animal1->makeSound();
    animal2->makeSound();

    // Clean up dynamically allocated memory
    delete animal1;
    delete animal2;

    return 0;
}
