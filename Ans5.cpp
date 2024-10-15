#include <iostream>
using namespace std;

class Animal {
public:
    virtual void makeSound() const = 0;  // Pure virtual function
};

class Cat : public Animal {
public:
    void makeSound() const override { cout << "Meow\n"; }
};

class Dog : public Animal {
public:
    void makeSound() const override { cout << "Woof\n"; }
};

int main() {
    Animal* a1 = new Cat();
    Animal* a2 = new Dog();
    a1->makeSound();
    a2->makeSound();
    delete a1; delete a2;
    return 0;
}
