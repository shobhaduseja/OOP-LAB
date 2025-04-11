#include <iostream>
using namespace std;

class Manager;

class Account {
private:
    string accnum;
    double balance;

public:
    Account(string acc = "", double balance = 0.0) : accnum(acc), balance(balance) {}

    void showaccount() const {
        cout << "your Account Number: " << accnum << endl;
        cout << "your Balance: " << balance << endl;
    }

    friend class Manager;
    friend void transferFunds(Account&, Account&, double);
};


class Manager {
public:
    void deposit(Account& acc, double amount) {
        acc.balance += amount;
        cout << "amount deposited " << endl;
    }


    void withdraw(Account& acc, double amount) {
        if (acc.balance >= amount) {
            acc.balance -= amount;
            cout << "amount withdrawn" << endl;
        } else {
            cout << "you have insufficient balance" << acc.accnum << endl;
        }
    }


    void displayAccount(const Account& acc) {
        acc.showaccount();
    }
};


void transferFunds(Account& from, Account& to, double amount) {
    if (from.balance >= amount) {
        from.balance -= amount;
        to.balance += amount;
        cout << "amount transferred" << endl;
    } else {
        cout << "no balance" << endl;
    }
}

int main() {
  
    Manager mgr;
    Account acc1("shoobydooby", 12000.0);
    Account acc2("pookiemon", 2000.0);

    mgr.displayAccount(acc1);
    mgr.displayAccount(acc2);
    mgr.deposit(acc1, 1000.0);
    mgr.deposit(acc2, 400.0);
    mgr.withdraw(acc1, 1500.0);
    transferFunds(acc1, acc2, 8000.0);
    mgr.displayAccount(acc1);
    mgr.displayAccount(acc2);

    return 0;
}
