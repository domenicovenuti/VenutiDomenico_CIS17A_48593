#ifndef SavingsAccount_H
#define SavingsAccount_H

#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class SavingsAccount {
public:
    SavingsAccount(float); //Constructor
    void Transaction(float); //Procedure
    float Total(float, int); //Savings Procedure
    float TotalRecursive(float, int);
    void toString(); //Output Properties
    void setBalance(float);
    void setFreqDeposit();
    void setFreqWithdraw();
private:
    float Withdraw(float); //Utility Procedure
    float Deposit(float); //Utility Procedure
    float Balance; //Property
    int FreqWithDraw; //Property
    int FreqDeposit; //Property
    float recursiveHelp(float, float, int);

};

SavingsAccount::SavingsAccount(float b1) {
    if (b1 > 0) {
        Balance = b1;
    }
    else {
        Balance = 0.00;
        Transaction(b1);
    }
    FreqWithDraw = 0;
    FreqDeposit = 0;
}
void SavingsAccount::Transaction(float t1) {
    if (t1 > 0) {
        Deposit(t1);
    }
    else {
        Withdraw(t1);
    }
}
float SavingsAccount::Total(float s1, int t1) {
    float b1 = 0.00;
    b1 = Balance;
    for (int x = 0; x < t1; x++) {
        b1 = b1 + b1 * s1;
    }
    return b1;
}
float SavingsAccount::TotalRecursive(float s1, int t1) {
    return recursiveHelp(Balance, s1, t1);
}
float SavingsAccount::recursiveHelp(float b1, float s1, int t1) {
    if (t1 == 0)
    {
        return b1;
    }

    float int1 = b1 * s1;
    return recursiveHelp(b1 + int1, s1, t1 - 1);
}
void SavingsAccount::toString() {
    cout << "Balance=" << Balance << endl << "WithDraws=" << FreqWithDraw << endl << "Deposits=" << FreqDeposit << endl;
}
float SavingsAccount::Withdraw(float w1) {
    if (Balance + w1 < 0) {
        cout << "WithDraw not Allowed" << endl;
    }
    else {
        setBalance(w1);
        setFreqWithdraw();
    }
    return Balance;
}
float SavingsAccount::Deposit(float d1) {
    setBalance(d1);
    setFreqDeposit();
    return Balance;
}
void SavingsAccount::setBalance(float b1) {
    Balance = Balance + b1;
}
void SavingsAccount::setFreqDeposit(){
    FreqDeposit++;
}
void SavingsAccount::setFreqWithdraw(){
    FreqWithDraw++;
}
#endif /*SavingsAccount*/
