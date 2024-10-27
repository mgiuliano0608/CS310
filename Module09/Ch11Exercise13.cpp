#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class bankAccount {
    private:

    int accountNumber;
    double balance;

    public:

    bankAccount() {

    }

    bankAccount(int accountNumber, double balance) {
        this->accountNumber = accountNumber;
        this->balance = balance;
    }

    int getAccountNumber() {
        return accountNumber;
    }

    void setAccountNumber(int accountNumber) {
        this->accountNumber = accountNumber;
    }

    double getBalance() {
        return balance;
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

    void printInfo() {
        cout << fixed << setprecision(2);
        locale loc("");
        cout << endl
             << "Account Number: " << accountNumber << endl
             << "Balance: $" << balance << endl;
    }
};

class checkingAccount : public bankAccount {
    private:
    double interestRate;
    double minBalance;
    double serviceCharge;

    public:

    checkingAccount() {

    }

    checkingAccount(int accountNumber, double balance, double interestRate, double minBalance, double serviceCharge)
            : bankAccount(accountNumber, balance) {
        this->interestRate = interestRate;
        this->minBalance = minBalance;
        this->serviceCharge = serviceCharge;
    }

    double getInterestRate() {
        return interestRate;
    }

    void setInterestRate(double interestRate) {
        this->interestRate = interestRate;
    }

    double getMinBalance() {
        return minBalance;
    }

    void setMinBalance(double minBalance) {
        this->minBalance = minBalance;
    }

    double getServiceCharge() {
        return serviceCharge;
    }

    void setServiceCharge(double serviceCharge) {
        this->serviceCharge = serviceCharge;
    }

    void postInterest() {
        deposit(getBalance() * interestRate);
    }

    bool isBalanceLessThanMin() {
        return getBalance() < minBalance;
    }

    bool withdrawal(double amount) {
        bool result = bankAccount::withdrawal(amount);

        if (getBalance() < minBalance) {
            bool scSuccessful = bankAccount::withdrawal(serviceCharge);
            if (scSuccessful) {
                cout << endl << "A service charge of $" << serviceCharge << " was charged to your account "
                     << "because the balance dropped below the $" << minBalance << " minimum." << endl;
            }
            else {
                cout << endl << "Unable to withdrawal $" << serviceCharge << " service charge due to lack of funds." << endl;
            }
        }

        return result;
    }

    void printInfo() {
        bankAccount::printInfo();

        cout << fixed << setprecision(2);
        locale loc("");
        cout << "Interest Rate: " << interestRate << endl
             << "Min Balance: $" << minBalance << endl
             << "Service Charge: $" << serviceCharge << endl;
    }
};

class savingsAccount : public bankAccount {
    private:
    double interestRate;

    public:

    savingsAccount() {

    }

    savingsAccount(int accountNumber, double balance, double interestRate)
            : bankAccount(accountNumber, balance) {
        this->interestRate = interestRate;
    }

    double getInterestRate() {
        return interestRate;
    }

    void setInterestRate(double interestRate) {
        this->interestRate = interestRate;
    }

    void postInterest() {
        deposit(getBalance() * interestRate);
    }

    bool withdrawal(double amount) {
        return bankAccount::withdrawal(amount);
    }

    void printInfo() {
        bankAccount::printInfo();

        cout << fixed << setprecision(2);
        locale loc("");
        cout << "Interest Rate: " << interestRate << endl;
    }
};

enum appState {
    CHOOSE_ACCOUNT,
    CHOOSE_ACTION,
    DEPOSIT,
    WITHDRAWAL,
    QUIT
};

int const CHECKING = 1;
int const SAVINGS = 2;

void chooseAccount();
void mainMenu();
void deposit();
void withdrawal();
void viewInfo();

checkingAccount checking;
savingsAccount savings;
int accountType;
appState state = CHOOSE_ACCOUNT;

int main() {
    checking = checkingAccount(112233, 100.0, 0.01, 100.0, 10.0);
    savings = savingsAccount(332211, 1500.0, 0.02);
    bool isRunning = true;

    cout << endl << endl
         << "**************************************************" << endl
         << "**                 Bellevue Bank                **" << endl
         << "**************************************************" << endl << endl;

    while (isRunning) {
        switch (state) {
            case CHOOSE_ACCOUNT:
                chooseAccount();
                break;
            case CHOOSE_ACTION:
                mainMenu();
                break;
            case DEPOSIT:
                deposit();
                break;
            case WITHDRAWAL:
                withdrawal();
                break;
            case QUIT:
                isRunning = false;
                break;
        }
        
    }

    return 0;
}

void chooseAccount() {
    int input;
    cout << endl
         << "Choose an account:" << endl
         << "1) Checking" << endl
         << "2) Savings" << endl
         << ">> ";
    cin >> input;

    if (input == CHECKING || input == SAVINGS) {
        accountType = input;
        state = CHOOSE_ACTION;
    }
    else {
        cout << endl << "Invalid choice. Try again." << endl;
    }
}

void mainMenu() {
    int input;
    cout << endl
         << "Choose an action:" << endl
         << "1) Deposit" << endl
         << "2) Withdrawal" << endl
         << "3) View Account Info" << endl
         << "4) Change Account" << endl
         << "5) Quit" << endl
         << ">> ";
    cin >> input;

    if (input == 1) {
        state = DEPOSIT;
    }
    else if (input == 2) {
        state = WITHDRAWAL;
    }
    else if (input == 3) {
        viewInfo();
    }
    else if (input == 4) {
        state = CHOOSE_ACCOUNT;
    }
    else if (input == 5) {
        state = QUIT;
    }
    else {
        cout << endl << "Invalid choice. Try again." << endl;
    }
}

void deposit() {
    double input;
    cout << endl << "How much would you like to deposit? ";
    cin >> input;

    if (accountType == CHECKING) {
        checking.deposit(input);
    }
    else if (accountType == SAVINGS) {
        savings.deposit(input);
    }

    state = CHOOSE_ACTION;
}

void withdrawal() {
    double input;
    bool isSuccessful;
    cout << endl << "How much would you like to withdrawal? ";
    cin >> input;

    if (accountType == CHECKING) {
        isSuccessful = checking.withdrawal(input);
    }
    else if (accountType == SAVINGS) {
        isSuccessful = savings.withdrawal(input);
    }

    if (!isSuccessful) {
        cout << endl << "Failed to make withdrawal." << endl;
    }

    state = CHOOSE_ACTION;
}

void viewInfo() {
    if (accountType == CHECKING) {
        checking.printInfo();
    }
    else if (accountType == SAVINGS) {
        savings.printInfo();
    }
}