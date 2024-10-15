#include <iostream>
#include <stdexcept>  // For exception handling
using namespace std;

class BankAccount {
private:
    string accountHolder;
    string accountNumber;
    double balance;

public:
    // Constructor to initialize account details
    BankAccount(string name, string accNum, double initialBalance) {
        accountHolder = name;
        accountNumber = accNum;
        balance = (initialBalance >= 0) ? initialBalance : 0;
    }

    // Deposit method
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    // Withdraw method with exception handling for insufficient balance
    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance! Available balance: " << balance << endl;
        } else if (amount <= 0) {
            cout << "Invalid withdrawal amount!" << endl;
        } else {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        }
    }

    // Method to check current balance
    double getBalance() const {
        return balance;
    }

    // Method to display account details
    void displayAccountDetails() const {
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: " << balance << endl;
    }
};

int main() {
    // Create a BankAccount object
    BankAccount account("John Doe", "1234567890", 1000);

    account.displayAccountDetails();
    account.deposit(500);
    account.withdraw(200);
    account.withdraw(2000);  // Insufficient balance
    cout << "Final Balance: " << account.getBalance() << endl;

    return 0;
}
