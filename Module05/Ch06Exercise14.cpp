#include <iostream>
#include <iomanip>

using namespace std;

const int LOW_INCOME_FREE_MINUTES = 30;
const int HIGH_INCOME_FREE_MINUTES = 20;
const double LOW_INCOME_RATE = 0.4;
const double HIGH_INCOME_RATE = 0.7;

double calculateBillAmount(double hourlyRate, int totalTime, bool isLowIncome);

int main()
{
    double hourlyRate;
    int totalTime;
    bool isLowIncome;
    string isLowIncomeText;
    double billAmount;

    // Get input from user
    cout << "What is the accounting hourly rate? ";
    cin >> hourlyRate;
    cout << "How much time (in minutes) was your consoltation? ";
    cin >> totalTime;
    cout << "Do you make $25,000 or less per year? (yes/no) ";
    cin >> isLowIncomeText;

    // Translate the user's low income answer to boolean
    if (isLowIncomeText == "yes")
        isLowIncome = true;
    else
        isLowIncome = false;

    // Calculate the bill amount
    billAmount = calculateBillAmount(hourlyRate, totalTime, isLowIncome);

    // Display result
    cout << fixed << setprecision(2);
    locale loc("");
    cout.imbue(loc);
    cout << "The bill amount due is $" << billAmount << endl << endl;

    return 0;
}

// Calculate the bill amount based on user input
double calculateBillAmount(double hourlyRate, int totalTime, bool isLowIncome)
{
    double billAmount = 0;
    int extraMinutes = 0;

    if (isLowIncome)
    {
        if (totalTime <= LOW_INCOME_FREE_MINUTES)
            return 0;

        extraMinutes = totalTime - LOW_INCOME_FREE_MINUTES;
        billAmount = hourlyRate * LOW_INCOME_RATE * ((double) extraMinutes / 60);
    }
    else
    {
        if (totalTime <= HIGH_INCOME_FREE_MINUTES)
            return 0;
        
        extraMinutes = totalTime - HIGH_INCOME_FREE_MINUTES;
        billAmount = hourlyRate * HIGH_INCOME_RATE * ((double) extraMinutes / 60);
    }

    return billAmount;
}