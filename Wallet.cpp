

#include "Wallet.h"
#include <iostream>
using namespace std;

int Wallet::totalWallets = 0;

void Wallet::copyName(const char name[])
{
    int i = 0;

    while (name[i] != '\0' && i < 49)
    {
        ownerName[i] = name[i];
        i++;
    }

    ownerName[i] = '\0';
}

Wallet::Wallet(int walletID, const char ownerName[], double balance)
    : walletID(walletID)
{
    copyName(ownerName);

    this->balance = balance;
    transactions = nullptr;
    transactionCount = 0;

    totalWallets++;
}

void Wallet::recordTransaction(double amount)
{
    double* temp = new double[transactionCount + 1];

    for (int i = 0; i < transactionCount; i++)
    {
        temp[i] = transactions[i];
    }

    temp[transactionCount] = amount;

    delete[] transactions;

    transactions = temp;
    transactionCount++;
}

void Wallet::deposit(double amount)
{
    if (amount <= 0)
    {
        cout << "Invalid deposit amount." << endl;
        return;
    }

    balance += amount;
    recordTransaction(amount);

    cout << "Deposit successful." << endl;
}

void Wallet::withdraw(double amount)
{
    if (amount <= 0)
    {
        cout << "Invalid withdrawal amount." << endl;
        return;
    }

    if (amount > balance)
    {
        cout << "Insufficient balance." << endl;
        return;
    }

    balance -= amount;
    recordTransaction(-amount);

    cout << "Withdrawal successful." << endl;
}

Wallet::Wallet(const Wallet& other)
    : walletID(other.walletID)
{
    copyName(other.ownerName);

    balance = other.balance;
    transactionCount = other.transactionCount;

    if (transactionCount > 0)
    {
        transactions = new double[transactionCount];

        for (int i = 0; i < transactionCount; i++)
        {
            transactions[i] = other.transactions[i];
        }
    }
    else
    {
        transactions = nullptr;
    }

    totalWallets++;
}

Wallet::~Wallet()
{
    delete[] transactions;
}

Wallet& Wallet::operator=(const Wallet& other)
{
    if (this != &other)
    {
        double* temp = nullptr;

        if (other.transactionCount > 0)
        {
            temp = new double[other.transactionCount];

            for (int i = 0; i < other.transactionCount; i++)
            {
                temp[i] = other.transactions[i];
            }
        }

        delete[] transactions;

        transactions = temp;
        transactionCount = other.transactionCount;

        copyName(other.ownerName);
        balance = other.balance;
    }

    return *this;
}

double Wallet::operator+(const Wallet& other) const
{
    return balance + other.balance;
}

double Wallet::operator-(const Wallet& other) const
{
    return balance - other.balance;
}

bool Wallet::operator==(const Wallet& other) const
{
    return balance == other.balance;
}

void Wallet::showTotalWallets()
{
    cout << "\nTotal wallets created: " << totalWallets << endl;
}

ostream& operator<<(ostream& out, const Wallet& wallet)
{
    out << "\nWallet ID: " << wallet.walletID;
    out << "\nOwner Name: " << wallet.ownerName;
    out << "\nBalance: Rs. " << wallet.balance;

    out << "\nTransaction History:" << endl;

    if (wallet.transactionCount == 0)
    {
        out << "No transactions." << endl;
    }

    for (int i = 0; i < wallet.transactionCount; i++)
    {
        if (wallet.transactions[i] > 0)
        {
            out << "Deposit: Rs. " << wallet.transactions[i] << endl;
        }
        else
        {
            out << "Withdraw: Rs. " << -wallet.transactions[i] << endl;
        }
    }

    return out;
}

void compareWallets(const Wallet& w1, const Wallet& w2)
{
    if (w1.balance > w2.balance)
    {
        cout << "Wallet 1 has a higher balance." << endl;
    }
    else if (w2.balance > w1.balance)
    {
        cout << "Wallet 2 has a higher balance." << endl;
    }
    else
    {
        cout << "Both wallets have equal balances." << endl;
    }
}
