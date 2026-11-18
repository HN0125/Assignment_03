#pragma once
#include <iostream>

class Wallet
{
private:
    const int walletID;
    char ownerName[50];
    double balance;
    double* transactions;
    int transactionCount;

    static int totalWallets;

    void recordTransaction(double amount);
    void copyName(const char name[]);

public:
    Wallet(int walletID, const char ownerName[], double balance);
    Wallet(const Wallet& other);
    ~Wallet();

    void deposit(double amount);
    void withdraw(double amount);

    static void showTotalWallets();

    double operator+(const Wallet& other) const;
    double operator-(const Wallet& other) const;
    bool operator==(const Wallet& other) const;

    Wallet& operator=(const Wallet& other);

    friend std::ostream& operator<<(std::ostream& out, const Wallet& wallet);

    friend void compareWallets(const Wallet& w1, const Wallet& w2);
};
