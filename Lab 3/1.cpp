#include <iostream>
using namespace std;

class Wallet {
private:
    string ownerName;
    float totalBalance;
    string transactionHistory[100];
    int transactionCount;

public:
    Wallet(string name, float balance = 0) {
        ownerName = name;
        totalBalance = balance;
        transactionCount = 0;
    }

    void addMoney(float money) {
        totalBalance += money;
        if (transactionCount < 100) {
            transactionHistory[transactionCount] = "Added: $" + to_string(money);
            transactionCount++;
        }
    }

    void spendMoney(float money) {
        if (money > totalBalance) {
            cout << "Insufficient funds!\n";
        } else {
            totalBalance -= money;
            if (transactionCount < 100) {
                transactionHistory[transactionCount] = "Spent: $" + to_string(money);
                transactionCount++;
            }
        }
    }

    void displayTransactionHistory() {
        if (transactionCount == 0) {
            cout << "No transactions yet.\n";
        } else {
            for (int i = 0; i < transactionCount; i++) {
                cout << transactionHistory[i] << endl;
            }
        }
    }
};

int main() {
    Wallet wallet("Saad", 25);
    int a = 0;  

    while (a != 4) {
        cout << "1. Add money\n";
        cout << "2. Spend money\n";
        cout << "3. Display Transaction history\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> a;

        switch (a) {
            case 1: {
                float money;
                cout << "Enter money to add: ";
                cin >> money;
                wallet.addMoney(money);
                break;
            }
            case 2: {
                float money1;
                cout << "Enter money to spend: ";
                cin >> money1;
                wallet.spendMoney(money1);
                break;
            }
            case 3:
                wallet.displayTransactionHistory();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
