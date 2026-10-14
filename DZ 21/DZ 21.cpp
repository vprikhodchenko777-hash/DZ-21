
#include <iostream>
#include <cstring>
#include <windows.h>
using namespace std;

class BankAccount
{
private:
    char owner[50];
    double balance;

public:
    void init(const char* newOwner)
    {
        strcpy_s(owner, 50, newOwner);
        balance = 0;
    }

    const char* getOwner() { return owner; }
    double getBalance() { return balance; }

    bool deposit(double amount);
    bool withdraw(double amount);
    void print();
};

bool BankAccount::deposit(double amount)
{
    if (amount <= 0)
        return false;

    balance += amount;
    return true;
}

bool BankAccount::withdraw(double amount)
{
    if (amount <= 0 || amount > balance)
        return false;

    balance -= amount;
    return true;
}

void BankAccount::print()
{
    cout << "Владелец: " << owner
        << ", баланс: " << balance << endl;
}

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    BankAccount account;

    account.init("Vladimir");

    account.deposit(1000);
    account.withdraw(300);

    if (!account.withdraw(5000))
        cout << "Ошибка: недостаточно средств!" << endl;

    account.print();

    return 0;
}
