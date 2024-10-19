#include <iostream>
using namespace std;

// Base class Vehicle
class Vehicle {
public:
    // Virtual method to display the type of vehicle
    virtual void displayType() const {
        cout << "This is a generic vehicle." << endl;
    }

    // Virtual method to display maximum speed
    virtual void maxSpeed() const {
        cout << "Max speed: Varies for different vehicles." << endl;
    }
};

// Derived class Car inheriting from Vehicle
class Car : public Vehicle {
public:
    void displayType() const override {
        cout << "This is a car." << endl;
    }

    void maxSpeed() const override {
        cout << "Max speed of car: 200 km/h" << endl;
    }
};

// Derived class Truck inheriting from Vehicle
class Truck : public Vehicle {
public:
    void displayType() const override {
        cout << "This is a truck." << endl;
    }

    void maxSpeed() const override {
        cout << "Max speed of truck: 120 km/h" << endl;
    }
};

int main() {
    // Create objects of Car and Truck
    Vehicle* vehicle1 = new Car();
    Vehicle* vehicle2 = new Truck();

    // Demonstrate polymorphism by calling methods through base class pointers
    vehicle1->displayType();
    vehicle1->maxSpeed();

    vehicle2->displayType();
    vehicle2->maxSpeed();

    // Clean up dynamically allocated memory
    delete vehicle1;
    delete vehicle2;

    return 0;
}
