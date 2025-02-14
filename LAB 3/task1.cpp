#include <iostream>
using namespace std;

class Wallet{
    private:

    int count = 0;
    string ownerName;
    double totalBalance = 0;
    double transactionHistory[100];
    
    public:
        void addMoney(double amount){
            if (count < 100){
                totalBalance += amount;
                transactionHistory[count] = totalBalance;
                count++;
                cout << "your amount has been added" << endl;
            }
            else{
                cout << "your transaction history is full" << endl;
                for (int i = 0; i < count; i++)
                {
                    transactionHistory[i] = 0;}
                count = 0;
                cout << "your transaction history is formatted" << endl;
            }
        }
        
        void spendMoney(double money){
            if (count < 100){
                totalBalance -= money;
                transactionHistory[count] = totalBalance;
                count++;
                cout << "account has been updated" << endl;
            }
            else{
                cout << "your transaction history is full" << endl;
                for (int i = 0; i < count; i++)
                {
                    transactionHistory[i] = 0;}
                count = 0;
                cout << "your transaction history is formatted" << endl;
            }
        }
        void display(){
            for (int i = 0; i < count; i++)
                {
                    cout<< "your transaction history is: "<< transactionHistory[i] << endl;
                }
            cout << "Your current balance is : " << totalBalance << endl;
            }
};

int main(){
    Wallet wallet1;
    double amount;
    cout << "Enter paisa to add: ";
    cin >> amount;
    wallet1.addMoney(amount);
    cout << "Enter paisa to spend: ";
    cin >> amount;
    wallet1.spendMoney(amount);
    wallet1.display();
    return 0;
}
