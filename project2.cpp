#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    char name[50];
    float balance;

public:
    void createAccount();
    void showAccount() const;
    void deposit(float);
    void withdraw(float);
    void writeToFile();
    void readFromFile(int);
};

void BankAccount::createAccount() {
    cout << "\nEnter Account Number: ";
    cin >> accountNumber;

    cout << "Enter Customer Name: ";
    cin.ignore();
    cin.getline(name, 50);

    cout << "Enter Initial Balance: ";
    cin >> balance;

    ofstream outFile("bank.dat", ios::binary | ios::app);

    outFile.write(reinterpret_cast<char*>(this), sizeof(*this));

    outFile.close();

    cout << "\nAccount Created Successfully!\n";
}

void BankAccount::showAccount() const {
    cout << "\nAccount Number : " << accountNumber;
    cout << "\nCustomer Name  : " << name;
    cout << "\nBalance        : " << balance << endl;
}

void BankAccount::deposit(float amount) {
    balance += amount;
}

void BankAccount::withdraw(float amount) {
    if (amount > balance) {
        cout << "\nInsufficient Balance!\n";
    } else {
        balance -= amount;
        cout << "\nWithdrawal Successful!\n";
    }
}

void BankAccount::writeToFile() {
    fstream file("bank.dat", ios::binary | ios::in | ios::out);

    BankAccount acc;

    while (file.read(reinterpret_cast<char*>(&acc), sizeof(acc))) {
        if (acc.accountNumber == accountNumber) {
            file.seekp(-static_cast<int>(sizeof(acc)), ios::cur);
            file.write(reinterpret_cast<char*>(this), sizeof(*this));
            break;
        }
    }

    file.close();
}

void BankAccount::readFromFile(int accNo) {
    ifstream inFile("bank.dat", ios::binary);

    BankAccount acc;
    bool found = false;

    while (inFile.read(reinterpret_cast<char*>(&acc), sizeof(acc))) {
        if (acc.accountNumber == accNo) {
            acc.showAccount();
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\nAccount Not Found!\n";
    }

    inFile.close();
}

void depositMoney(int accNo, float amount) {
    fstream file("bank.dat", ios::binary | ios::in | ios::out);

    BankAccount acc;

    while (file.read(reinterpret_cast<char*>(&acc), sizeof(acc))) {
        if (accNo == acc.accountNumber) {
            acc.deposit(amount);

            file.seekp(-static_cast<int>(sizeof(acc)), ios::cur);

            file.write(reinterpret_cast<char*>(&acc), sizeof(acc));

            cout << "\nAmount Deposited Successfully!\n";
            break;
        }
    }

    file.close();
}

void withdrawMoney(int accNo, float amount) {
    fstream file("bank.dat", ios::binary | ios::in | ios::out);

    BankAccount acc;

    while (file.read(reinterpret_cast<char*>(&acc), sizeof(acc))) {
        if (accNo == acc.accountNumber) {
            acc.withdraw(amount);

            file.seekp(-static_cast<int>(sizeof(acc)), ios::cur);

            file.write(reinterpret_cast<char*>(&acc), sizeof(acc));

            break;
        }
    }

    file.close();
}

int main() {
    BankAccount acc;
    int choice, accNo;
    float amount;

    do {
        cout << "\n==============================";
        cout << "\n BANK MANAGEMENT SYSTEM";
        cout << "\n==============================";
        cout << "\n1. Create Account";
        cout << "\n2. Deposit Money";
        cout << "\n3. Withdraw Money";
        cout << "\n4. Balance Inquiry";
        cout << "\n5. Exit";
        cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            acc.createAccount();
            break;

        case 2:
            cout << "\nEnter Account Number: ";
            cin >> accNo;

            cout << "Enter Amount to Deposit: ";
            cin >> amount;

            depositMoney(accNo, amount);
            break;

        case 3:
            cout << "\nEnter Account Number: ";
            cin >> accNo;

            cout << "Enter Amount to Withdraw: ";
            cin >> amount;

            withdrawMoney(accNo, amount);
            break;

        case 4:
            cout << "\nEnter Account Number: ";
            cin >> accNo;

            acc.readFromFile(accNo);
            break;

        case 5:
            cout << "\nThank You!\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 5);

    return 0;
}
