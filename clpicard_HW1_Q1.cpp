#include <string>
#include <array>
#include <iostream>

struct Check {
    int CheckNum;
    std::pmr::string CheckMemo;
    float CheckAmount;

};
// This was a suggested edit from CLion/ChatGPT --> Don't really understand
std::ostream& operator<<(std::ostream& os, const Check& check) {
    os << check.CheckAmount ;
    return os;
}

class CheckBook {

private:

    float balance;
    Check checks[5];
    float lastDeposit;
    int numOfChecks;
    const int checkLimit = 5;

public:

    CheckBook(): balance(0), numOfChecks(0) {}

    CheckBook(const float initialBalance ): balance(initialBalance), numOfChecks(0) {}

    void deposit(const float amount) {

        balance += amount;
        lastDeposit = amount;
        std::cout << "You deposited:$" << amount << ". Your new balance is:$" << balance<<std::endl;
    };

    void displayChecks() const {
        for (int i = numOfChecks - 1; i >= 0; --i) {
            std::cout << "Check " << i + 1 << ": $" << checks[i] << "\n";
        }
    };


    bool writeCheck(const float amount) {
        if (amount <= balance) {
            if (numOfChecks >= checkLimit) {
                std::cout << "No more checks.\n";
                return false;
            }
            else {

                checks[numOfChecks].CheckAmount = amount;
                checks[numOfChecks].CheckNum = numOfChecks + 1;

                balance -= amount;
                numOfChecks += 1;
                std::cout << "Your new balance is:$" << balance << "\n";

            }

        }
        return true;
    }
};

int main() {
    CheckBook Account;
    Account.deposit(500);
    Account.writeCheck(150);
    Account.writeCheck(200);
    Account.displayChecks();
}
