#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Aspect for logging transactions
class LoggerAspect
{
public:
    static void LogTransaction(const string &accountType, double amount)
    {
        cout << "Transaction logged - Account Type: " << accountType << ", Amount: " << amount << endl;
    }
};

// Base account class
class Account
{
protected:
    double balance;

public:
    Account(double initialBalance) : balance(initialBalance) {}

    double GetBalance() const
    {
        return balance;
    }

    virtual void Withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            LoggerAspect::LogTransaction("Generic", amount);
        }
        else
        {
            cout << "Insufficient balance or invalid amount." << endl;
        }
    }
};

// Checking account class
class CheckingAccount : public Account
{
public:
    CheckingAccount(double initialBalance) : Account(initialBalance) {}

    void Withdraw(double amount) override
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            LoggerAspect::LogTransaction("Checking", amount);
        }
        else
        {
            cout << "Insufficient balance or invalid amount." << endl;
        }
    }
};

// Savings account class
class SavingsAccount : public Account
{
public:
    SavingsAccount(double initialBalance) : Account(initialBalance) {}

    void Withdraw(double amount) override
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            LoggerAspect::LogTransaction("Savings", amount);
        }
        else
        {
            cout << "Insufficient balance or invalid amount." << endl;
        }
    }
};

// Investment account class
class InvestmentAccount : public Account
{
public:
    InvestmentAccount(double initialBalance) : Account(initialBalance) {}
    void Withdraw(double amount) override
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            LoggerAspect::LogTransaction("Investment", amount);
        }
        else
        {
            cout << "Insufficient balance or invalid amount." << endl;
        }
    }
};

int main()
{
    // Create accounts
    CheckingAccount checkingAccount(500);
    SavingsAccount savingsAccount(1000);
    InvestmentAccount investmentAccount(2000);

    // Make withdrawals and test logging
    checkingAccount.Withdraw(200);
    savingsAccount.Withdraw(400);
    investmentAccount.Withdraw(1000);
    checkingAccount.Withdraw(600);

    return 0;
}
