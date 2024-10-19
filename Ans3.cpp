#include <iostream>
#include <cmath>  // For M_PI (pi value)
using namespace std;

// Base class Shape with a virtual function area()
class Shape {
public:
    // Virtual function to be overridden by derived classes
    virtual double area() const = 0;  // Pure virtual function
};

// Derived class Circle that overrides the area() function
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    // Overriding the area() function
    double area() const override {
        return M_PI * radius * radius;
    }
};

// Derived class Rectangle that overrides the area() function
class Rectangle : public Shape {
private:
    double length, width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    // Overriding the area() function
    double area() const override {
        return length * width;
    }
};

int main() {
    // Create objects of Circle and Rectangle
    Shape* shape1 = new Circle(5.0);   // Polymorphic behavior
    Shape* shape2 = new Rectangle(4.0, 6.0);

    // Display the areas using base class pointers
    cout << "Area of Circle: " << shape1->area() << endl;
    cout << "Area of Rectangle: " << shape2->area() << endl;

    // Clean up dynamically allocated memory
    delete shape1;
    delete shape2;

    return 0;
}
