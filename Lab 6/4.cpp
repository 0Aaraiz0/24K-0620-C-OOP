#include <iostream>
using namespace std;

class Account {
protected:
    int accountNumber;
    float balance;

public:
    Account(int a, float b) {
        accountNumber = a;
        balance = b;
    }

    virtual void displayDetails() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
};

class SavingsAccount : public Account {
    float interestRate;

public:
    SavingsAccount(int a, float b, float i) : Account(a, b) {
        interestRate = i;
    }

    void displayDetails() override {
        Account::displayDetails();
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

class CheckingAccount : public Account {
    float overdraftLimit;

public:
    CheckingAccount(int a, float b, float o) : Account(a, b) {
        overdraftLimit = o;
    }

    void displayDetails() override {
        Account::displayDetails();
        cout << "Overdraft Limit: " << overdraftLimit << endl;
    }
};

int main() {
    int accNum;
    float balance, interestRate, overdraftLimit;

    cout << "Enter Savings Account Details:\n";
    cout << "Account Number: ";
    cin >> accNum;
    cout << "Balance: ";
    cin >> balance;
    cout << "Interest Rate (%): ";
    cin >> interestRate;

    SavingsAccount savings(accNum, balance, interestRate);

    cout << "\nEnter Checking Account Details:\n";
    cout << "Account Number: ";
    cin >> accNum;
    cout << "Balance: ";
    cin >> balance;
    cout << "Overdraft Limit: ";
    cin >> overdraftLimit;

    CheckingAccount checking(accNum, balance, overdraftLimit);

    cout << "\nSavings Account Details:\n";
    savings.displayDetails();

    cout << "\nChecking Account Details:\n";
    checking.displayDetails();

    return 0;
}
