#include <iostream>
using namespace std;

class Person {
public:
    void displayPerson() { cout << "Person\n"; }
};

class Employee {
public:
    void displayEmployee() { cout << "Employee\n"; }
};

class Manager : public Person, public Employee {
public:
    void displayManager() { cout << "Manager\n"; }
};

int main() {
    Manager m;
    m.displayPerson();
    m.displayEmployee();
    m.displayManager();
    return 0;
}
