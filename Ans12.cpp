#include <iostream>
#include <string>
using namespace std;

// Base class Person
class Person {
protected:
    string name;
    int age;

public:
    Person(const string& n, int a) : name(n), age(a) {}

    void displayPersonInfo() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

// Base class Employee
class Employee {
protected:
    string employeeID;

public:
    Employee(const string& id) : employeeID(id) {}

    void displayEmployeeInfo() {
        cout << "Employee ID: " << employeeID << endl;
    }
};

// Derived class Manager
class Manager : public Person, public Employee {
private:
    string department;

public:
    Manager(const string& n, int a, const string& id, const string& dep)
        : Person(n, a), Employee(id), department(dep) {}

    void displayManagerInfo() {
        displayPersonInfo();          // Display info from Person
        displayEmployeeInfo();       // Display info from Employee
        cout << "Department: " << department << endl;
    }
};

int main() {
    Manager manager("Alice Johnson", 35, "MGR123", "Sales");

    cout << "Manager Information:\n";
    manager.displayManagerInfo();

    return 0;
}
