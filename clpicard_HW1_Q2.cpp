#include <iostream>
#include <string>
using namespace std;


class Check {
private:
    int checkNum;
    string checkMemo;
    float checkAmount;
public:

    static int counter;

// Constructor
    Check() : checkNum(0), checkMemo(""), checkAmount(0) {
        checkNum = counter++;
    }

    // Getters and setters.
    int getCheckNum() const { return checkNum; }
    void setCheckNum(int n) { checkNum = n; }

    string getCheckMemo() const { return checkMemo; }
    void setCheckMemo(const string &memo) { checkMemo = memo; }

    float getCheckAmount() const { return checkAmount; }
    void setCheckAmount(float amount) { checkAmount = amount; }
};


int Check::counter = 0;


class CheckBook {
private:
    float balance;
    static const int N = 5;
    Check checks[N];
    int numOfChecks;
public:
    static int allChecks;

    //Constructor
    CheckBook(float initialBalance) : balance(initialBalance), numOfChecks(0) {}

    //getter for allchecks
    int getallChecks() const { return allChecks; }

    bool writeCheck(float amount) {
        if(numOfChecks >= N || allChecks >= 10 || balance < amount)
            return false;
        cout << "memo?" << endl;
        string memo;
        cin >> memo;

        checks[numOfChecks].setCheckAmount(amount);
        checks[numOfChecks].setCheckMemo(memo);
        checks[numOfChecks].setCheckNum(numOfChecks);
        balance -= amount;

        numOfChecks+=1;
        allChecks+=1;

        return true;
    }


    void displayChecks() const {
        for (int i = numOfChecks - 1; i >= 0; i--) {
            cout << checks[i].getCheckAmount() << " "
                 << checks[i].getCheckNum() << " "
                 << checks[i].getCheckMemo() << endl;
        }
    }
};


int CheckBook::allChecks = 0;

int main() {

    CheckBook cb1(1000), cb2(500);

    for (int i = 0; i < 10; i++) {
        cb1.writeCheck(150);
        cb2.writeCheck(130);
    }

    cout << "cb1 check details" << endl;
    cb1.displayChecks();
    cout << "cb2 check details" << endl;
    cb2.displayChecks();

    cout << cb1.getallChecks() << endl;
    cout << cb2.getallChecks() << endl;

    return 0;
}
