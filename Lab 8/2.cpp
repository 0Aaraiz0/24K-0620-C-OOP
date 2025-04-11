#include <iostream>
#include <string>

using namespace std;

class Manager;  

class Account {
private:
    string accountNumber;
    double balance;

public:
    Account(string accNum, double initialBalance)
        : accountNumber(accNum), balance(initialBalance) {}

    friend class Manager;

    friend void transferFunds(Account& from, Account& to, double amount);
};

class Manager {
public:
    void displayAccount(const Account& acc) const {
        cout << "Account Number: " << acc.accountNumber << "\n";
        cout << "Balance: $" << acc.balance << "\n";
    }

    void deposit(Account& acc, double amount) const {
        if (amount > 0) {
            acc.balance += amount;
            cout << "Deposited $" << amount << " into " << acc.accountNumber << "\n";
        } else {
            cout << "Invalid deposit amount.\n";
        }
    }

    void withdraw(Account& acc, double amount) const {
        if (amount > 0 && acc.balance >= amount) {
            acc.balance -= amount;
            cout << "Withdrew $" << amount << " from " << acc.accountNumber << "\n";
        } else {
            cout << "Insufficient funds or invalid amount.\n";
        }
    }
};

void transferFunds(Account& from, Account& to, double amount) {
    if (amount <= 0) {
        cout << "Invalid transfer amount.\n";
        return;
    }

    if (from.balance >= amount) {
        from.balance -= amount;
        to.balance += amount;
        cout << "Transferred $" << amount << " from " << from.accountNumber
             << " to " << to.accountNumber << "\n";
    } else {
        cout << "Transfer failed: Insufficient balance in " << from.accountNumber << "\n";
    }
}

int main() {
    Manager mgr;

    Account acc1("A123", 1000.0);
    Account acc2("B456", 500.0);

    cout << "Initial Account States:\n";
    mgr.displayAccount(acc1);
    mgr.displayAccount(acc2);
    cout << "-----------------------------\n";

    mgr.deposit(acc1, 300.0);
    mgr.withdraw(acc2, 200.0);

    cout << "After Deposit and Withdraw:\n";
    mgr.displayAccount(acc1);
    mgr.displayAccount(acc2);
    cout << "-----------------------------\n";

    transferFunds(acc1, acc2, 400.0);

    cout << "After Transfer:\n";
    mgr.displayAccount(acc1);
    mgr.displayAccount(acc2);

    return 0;
}
