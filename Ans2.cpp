#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance;

public:
    BankAccount() : balance(0) {}
    void deposit(double amount) { balance += amount; }
    bool withdraw(double amount) {
        if (amount > balance) return false;
        balance -= amount;
        return true;
    }
    double getBalance() const { return balance; }
};

int main() {
    BankAccount account;
    account.deposit(1000);
    if (account.withdraw(500)) cout << "Withdrawal successful\n";
    cout << "Balance: " << account.getBalance() << endl;
    return 0;
}
