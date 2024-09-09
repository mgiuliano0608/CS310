#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double netBalance;
    double payment;
    double interestRate;
    double averageDailyBalance;
    double interest;
    int d1;
    int d2;
    
    // Display header
    cout << endl << "-------------------------------------------------" << endl;
    cout << "               INTEREST CALCULATOR" << endl;
    cout << endl << "-------------------------------------------------" << endl << endl;

    // Get user input
    cout << "What is the net balance? ";
    cin >> netBalance;
    cout << "How much was the payment? ";
    cin >> payment;
    cout << "How many days are in the billing cycle? ";
    cin >> d1;
    cout << "How many days before the billing cycle end was the payment made? ";
    cin >> d2;
    cout << "What is the monthly interest rate? ";
    cin >> interestRate;

    // Calculations
    averageDailyBalance = (netBalance * d1 - payment * d2) / d1;
    interest = averageDailyBalance * interestRate;

    // Display calculation result
    cout << endl << fixed << setprecision(2);
    locale loc("");
    cout.imbue(loc);
    cout << endl << "                 --- Results ---" << endl;
    cout << "*************************************************" << endl;
    cout << "Net balance: $" << netBalance << endl;
    cout << "Payment amount: $" << payment << endl;
    cout << "Days in billing cycle: " << d1 << endl;
    cout << "Days from payment to billing cycle end: " << d2 << endl;
    cout << "Monthly interest rate: " << interestRate * 100 << "%" << endl;
    cout << "Average daily balance: $" << averageDailyBalance << endl;
    cout << "Interest amount: $" << interest << endl;
    cout << "*************************************************" << endl << endl;

    return 0;
}
