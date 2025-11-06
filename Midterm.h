#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>   // added for completeness
using namespace std;

class BankAccount {
private:
    double balance;

    // Helper function to save a transaction to file
    void saveTransaction(const string& type, double amount) {
        ofstream file("transactions.txt", ios::app); // append mode
        if (file.is_open()) {
            file << type << ": $" << amount
                << " | Balance after: $" << balance << endl;
            file.close();
        }
        else {
            cout << "Error: Could not open transactions.txt" << endl;
        }
    }

public:
    BankAccount() {
        balance = 0.0;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited $" << amount << ". Current Balance: $" << balance << endl;
        saveTransaction("Deposit", amount);
    }

    void makePurchase(const string& item, double cost) {
        if (cost > balance) {
            cout << "Insufficient funds for " << item << endl;
        }
        else {
            balance -= cost;
            cout << "Purchased " << item << " for $" << cost
                << ". New Balance: $" << balance << endl;
            saveTransaction("Purchase - " + item, cost);
        }
    }

    void displayBalance() const {
        cout << "Current Balance: $" << balance << endl;
    }

    // Displays all past transactions from file
    void displayTransactionHistory() const {
        ifstream file("transactions.txt");
        if (file.is_open()) {
            cout << "\n--- Transaction History ---\n";
            string line;
            while (getline(file, line)) {
                cout << line << endl;
            }
            cout << "--- End of History ---\n";
            file.close();
        }
        else {
            cout << "No transaction history found.\n";
        }
    }
};

// === MAIN ===
int main() {
    BankAccount myAccount;

    // Example test sequence
    myAccount.deposit(100.00);
    myAccount.makePurchase("Coffee", 4.50);
    myAccount.makePurchase("Book", 25.00);
    myAccount.displayBalance();

    // Show all saved transactions
    myAccount.displayTransactionHistory();

    cout << "\nTransactions have been recorded in transactions.txt\n";
    return 0;
}
