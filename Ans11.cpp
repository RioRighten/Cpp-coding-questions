#include <iostream>
using namespace std;

// Interface for Payment
class Payment {
public:
    virtual void processPayment(double amount) = 0;  // Pure virtual function
};

// Derived class for Credit Card Payment
class CreditCardPayment : public Payment {
public:
    void processPayment(double amount) override {
        cout << "Processing credit card payment of $" << amount << endl;
        // Logic for processing credit card payment
    }
};

// Derived class for PayPal Payment
class PayPalPayment : public Payment {
public:
    void processPayment(double amount) override {
        cout << "Processing PayPal payment of $" << amount << endl;
        // Logic for processing PayPal payment
    }
};

int main() {
    Payment* payment1 = new CreditCardPayment();  // Creating a CreditCardPayment object
    Payment* payment2 = new PayPalPayment();      // Creating a PayPalPayment object

    double amount;

    cout << "Enter the amount to be processed: ";
    cin >> amount;

    payment1->processPayment(amount);  // Processing credit card payment
    payment2->processPayment(amount);  // Processing PayPal payment

    // Clean up dynamic memory
    delete payment1;
    delete payment2;

    return 0;
}
