
#include "Account.cpp"
#include <iostream>


int main() {
    SavingsAccount savings;
    savings.setValues("S123", "John Doe", 1000, 0.02);
    CurrentAccount current;
    current.setValues("C456", "Jane Doe", 2000, 500);

    savings.displayDetails();
    current.displayDetails();

    cout << "Account details after deposit and withdrawal \n";
    savings.deposit(500);
    current.withdraw(1000);
    
    savings.displayDetails();
    current.displayDetails();

    // Transfer 300 from savings to current
    cout << "Account details after transfer";
    current + savings;

    savings.displayDetails();
    current.displayDetails();

    return 0;
}