#include <iostream>
using namespace std;

class Payment {
public:
    virtual void processPayment() const = 0;  // Pure virtual function
};

class CreditCardPayment : public Payment {
public:
    void processPayment() const override {
        cout << "Processing Credit Card Payment\n";
    }
};

class PayPalPayment : public Payment {
public:
    void processPayment() const override {
        cout << "Processing PayPal Payment\n";
    }
};

int main() {
    Payment* p1 = new CreditCardPayment();
    Payment* p2 = new PayPalPayment();
    p1->processPayment();
    p2->processPayment();
    delete p1; delete p2;
    return 0;
}
