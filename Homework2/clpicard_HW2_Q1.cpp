//
// Created by caden.picard on 2/17/2025.
//
/*************************************************************************
** Author : Caden Picard
** Program : CheckBook Simulator
** Date Created : February 17, 2025
** Date Last Modified : February 17, 2025
** Usage : No command line arguments
**
** Problem: CheckBook class manages checks, lets user withdraw, and allows deposits by writing a check.
The program should:
- Track account activity like deposits, balances, and written checks
- Create more checks when the checkbook has half of its checks left.
- Write random memos
- Test the Checkbook class with a test case.
*************************************************************************/


#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Defining Check struct
struct Check {
    int CheckNum;
    string CheckMemo;
    float CheckAmount;

    // default constructor
    Check() : CheckNum(0), CheckMemo(""), CheckAmount(0) {}

    // Custom constructor
    Check(float amount, int check_num) : CheckAmount(amount), CheckNum(check_num) {}

    // Is the checkAmount more than the input?
    bool operator>(float value) const {
        return CheckAmount > value;
    }

    // overload to print out
    // I got some help writing this as I'm still having a hard time with syntax)
    friend ostream& operator<<(ostream& os, const Check& c) {
        os << "Check #" << c.CheckNum << " - Amount: " << c.CheckAmount << " - Memo: " << c.CheckMemo;
        return os;
    }
};

// Create the Checkbook Class
class CheckBook {
private:
    float balance; // keep track of balance
    Check* chkPtr; // pointer with check data type
    float lastDeposit; // keep last deposited amount
    int numOfChecks; // keep track of number of checks written
    int checkBookSize; // how many checks are left and have been used

    // Random memos
    string memos[8] = {"Clown School", "Clown makeup", "Train ticket", "Vocal lessons", "Mini Pony", "Hot Air balloon ride", "Cases of Vodka", "Crossfit Membership"};

public:
    // Default constructor
    CheckBook() : balance(0), numOfChecks(0), checkBookSize(4), lastDeposit(0) {
        chkPtr = new Check[checkBookSize];
    }
    //Secondary constructor given initial balance
    CheckBook(float begBalance) : balance(begBalance), numOfChecks(0), checkBookSize(2), lastDeposit(0) {
        chkPtr = new Check[checkBookSize];
    }

    //Destroy!
    ~CheckBook() {
        delete[] chkPtr;
    }

    //Copy Constructor
    CheckBook(const CheckBook& otherguy) {
        balance = otherguy.balance;
        lastDeposit = otherguy.lastDeposit;
        numOfChecks = otherguy.numOfChecks;
        checkBookSize = otherguy.checkBookSize;
        chkPtr = new Check[otherguy.checkBookSize];
    }


    CheckBook& operator=(const CheckBook& other) {
        if (this != &other) { // Got some help from AI for this portion
            delete[] chkPtr;
            balance = other.balance;
            lastDeposit = other.lastDeposit;
            numOfChecks = other.numOfChecks;
            checkBookSize = other.checkBookSize;
            chkPtr = new Check[other.checkBookSize];
        }
        return *this;
    }

    // deposit money into bank account
    void deposit(float deposit_amount) {
        balance += deposit_amount;
        lastDeposit = deposit_amount;
    }






int main() {

    return 0;
}