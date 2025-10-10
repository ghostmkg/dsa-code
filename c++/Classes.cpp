#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string name;
    int accountNumber;
    double balance;

public:
    void createAccount() {
        cout << "Enter account holder name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter account number: ";
        cin >> accountNumber;
        balance = 0;
        cout << "Account created successfully!\n";
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << endl;
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance!" << endl;
        } else {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        }
    }

    void displayAccount() {
        cout << "\nAccount Holder: " << name
             << "\nAccount Number: " << accountNumber
             << "\nBalance: " << balance << endl;
    }
};

int main() {
    BankAccount account;
    account.createAccount();

    account.deposit(5000);
    account.withdraw(2000);
    account.displayAccount();

    return 0;
}
