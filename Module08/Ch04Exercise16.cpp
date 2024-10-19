#include <iostream>
#include <string>
#include <chrono>

using namespace std;



class bankAccount {
    private:

    static int generateAccountNumber() {
        static int accountCount;

        accountCount++;
        return accountCount;
    }

    string name;
    int accountNumber;
    string accountType;
    double balance;
    double interestRate;

    public:

    static const string TYPE_CHECKING;
    static const string TYPE_SAVINGS;

    bankAccount() {

    }

    bankAccount(string name, string accountType, double interestRate) {
        this->name = name;
        this->accountNumber = generateAccountNumber();
        this->accountType = accountType;
        this->balance = 0.0;
        this->interestRate = interestRate;
    }

    string getName() {
        return name;
    }

    void setName(string name) {
        this->name = name;
    }

    int getAccountNumber() {
        return accountNumber;
    }

    string getAccountType() {
        return accountType;
    }

    double getBalance() {
        return balance;
    }

    double getInterestRate() {
        return interestRate;
    }

    void setInterestRate(double interestRate) {
        this->interestRate = interestRate;
    }

    bool deposit(double amount) {
        if (amount <= 0) {
            return false;
        }

        balance += amount;
        return true;
    }

    bool withdrawal(double amount) {
        if (amount <= 0 || balance < amount) {
            return false;
        }

        balance -= amount;
        return true;
    }

    
};

const string bankAccount::TYPE_CHECKING = "Checking";
const string bankAccount::TYPE_SAVINGS = "Savings";

bankAccount* accounts = new bankAccount[10] ;

int main() {
    
    accounts[0] = bankAccount("Michael", bankAccount::TYPE_CHECKING, 0.015);
    accounts[0].deposit(1000.0);
    accounts[0].withdrawal(25.0);
    accounts[0].deposit(150.0);
    accounts[0].withdrawal(10.0);

    accounts[1] = bankAccount("Megan", bankAccount::TYPE_SAVINGS, 0.025);
    accounts[1].deposit(500.0);
    accounts[1].withdrawal(15.0);
    accounts[1].deposit(200.0);
    accounts[1].withdrawal(2000.0);  // Should not withdrawal anything due to insufficient funds
    accounts[1].withdrawal(150.0);

    for (int i = 0; i < 2; i++) {
        bankAccount b = accounts[i];
        cout << b.getAccountType() << " - " << b.getName() << " (" << b.getAccountNumber()
             << ") Balance: " << b.getBalance() << "  Interest Rate: " << b.getInterestRate() << endl;
    }

    delete [] accounts;

    return 0;
}