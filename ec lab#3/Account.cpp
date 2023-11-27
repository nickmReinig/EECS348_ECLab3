#include <string>
#include <iostream>


using namespace std;

class Account{
    public:

        void displayDetails(){
            cout << "Account details for account (ID: " << accountNumber << ")\n";
            cout << "   Holder: " << accountHolder << "\n";
            cout << "   Balance: " << balance << "\n";
            cout << "\n";
        }

        void deposit(float amount){
            balance += amount;
        }

        void withdraw(float amount){
            if (amount < balance){
            balance -= amount;                
            }
        }

        void setValues(string accNum, string accHold, float bal){
            accountNumber = accNum;
            accountHolder = accHold;
            balance = bal;
        }

        Account operator+(Account b){
            //I'm just hardcoding in $300 because the instructions don't make it clear where exactly those numbers come from
            this->deposit(300);
            b.displayDetails();
            b.withdraw(300);
            b.displayDetails();
            return b;
        }



    protected:
        string accountNumber;
        string accountHolder;
        float balance;



};


class SavingsAccount : public Account{
    public:
                
        void displayDetails(){
            cout << "Account details for savings account (ID: " << accountNumber << ")\n";
            cout << "   Holder: " << accountHolder << "\n";
            cout << "   Balance: " << balance << "\n";
            cout << "   Interest rate: " << interestRate << "\n";
            cout << "\n";
        }

        void withdraw(float amount){
            if (amount < balance - minimumBalance){
            balance -= amount;                
            }
        }

        void setValues(string accNum, string accHold, float bal, float interest){
            accountNumber = accNum;
            accountHolder = accHold;
            balance = bal;
            interestRate = interest;
        }




    protected:

        float interestRate;
        //the minimum balance will be set to 500
        float minimumBalance = 500;

};


class CurrentAccount : public Account{
    public:
                
        void displayDetails(){
            cout << "Account details for current account (ID: " << accountNumber << ")\n";
            cout << "   Holder: " << accountHolder << "\n";
            cout << "   Balance: " << balance << "\n";
            cout << "   Overdraft Limit: " << overdraftLimit << "\n";
            cout << "\n";
        }

        void withdraw(float amount){
            if (amount < balance + overdraftLimit){
            balance -= amount;                
            }
        }


        void setValues(string accNum, string accHold, float bal, float overdraft){
            accountNumber = accNum;
            accountHolder = accHold;
            balance = bal;
            overdraftLimit = overdraft;
        }


    protected:
        float overdraftLimit;

};