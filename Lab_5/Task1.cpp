#include <iostream>

using namespace std;

class ATM
{
    int pin;

public:
    ATM() {}

    ATM(int pin)
    {
        this->pin = pin;
    }

    int getPIN()
    {
        return pin;
    }
};

class BankAccount
{
    int accountID;
    double balance;
    int *transactionHistory;
    int numTransactions;
    ATM atm;

public:
    BankAccount(int accountID, double balance, int transactionHistory[], int numTransactions, ATM atm)
    {
        this->accountID = accountID;
        this->balance = balance;
        this->numTransactions = numTransactions;
        this->transactionHistory = new int[this->numTransactions];
        this->atm = atm;
        // Copying the provided transactions
        for (int i = 0; i < this->numTransactions; i++)
        {
            this->transactionHistory[i] = transactionHistory[i];
        }
    };

    BankAccount(BankAccount &bankAccount)
    {
        this->accountID = bankAccount.accountID;
        this->balance = bankAccount.balance;
        this->numTransactions = bankAccount.numTransactions;
        this->transactionHistory = bankAccount.transactionHistory;
        this->atm = bankAccount.atm;
    }

    ~BankAccount()
    {
        delete[] this->transactionHistory;
    }

    void display()
    {
        cout << "Account ID: " << this->accountID << endl;
        cout << "ATM PIN: " << this->atm.getPIN() << endl;
        cout << "Balance: " << this->balance << endl;
        cout << "Total number of transactions: " << this->numTransactions << endl;
        cout << "Transaction History:" << endl;

        for (int i = 0; i < numTransactions; i++)
        {
            cout << "Transaction " << i + 1 << ": " << transactionHistory[i] << endl;
        }

        cout << endl
             << endl;
    }

    void updateTransactionHistory(int transactionHistory[], int numOfTransactions)
    {
        // Dealloc old records
        delete[] this->transactionHistory;

        // Alloc new records
        this->numTransactions = numOfTransactions;
        this->transactionHistory = new int[numOfTransactions];

        // Copy new records
        for (int i = 0; i < numOfTransactions; i++)
        {
            this->transactionHistory[i] = transactionHistory[i];
        }
    }
};

int main()
{
    int transactionHistory[4] = {100, -10, 89, 23};
    ATM atm(1234);
    BankAccount account(101, 1000.0, transactionHistory, 4, atm);

    BankAccount accountCopy(account);
    account.display();
    accountCopy.display();

    int newTransactionHistory[7] = {123, 200, -978, 100, -10, 89, 23};

    accountCopy.updateTransactionHistory(newTransactionHistory, 7);

    accountCopy.display();
}