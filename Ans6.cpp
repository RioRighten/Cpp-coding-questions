#include <iostream>
using namespace std;

class Vehicle {
public:
    virtual void displayType() const = 0;
    virtual int maxSpeed() const = 0;
};

class Car : public Vehicle {
public:
    void displayType() const override { cout << "Car\n"; }
    int maxSpeed() const override { return 180; }
};

class Truck : public Vehicle {
public:
    void displayType() const override { cout << "Truck\n"; }
    int maxSpeed() const override { return 120; }
};

int main() {
    Vehicle* v1 = new Car();
    Vehicle* v2 = new Truck();
    v1->displayType();
    cout << "Max speed: " << v1->maxSpeed() << " km/h\n";
    delete v1; delete v2;
    return 0;
}
