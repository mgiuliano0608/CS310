#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

// Displays the app title centered in the banner
void displayTitle()
{
    string title = "SIMPLE FAKE TAX CALCULATOR";
    int bannerWidth = 50;
    char bannerChar = "-";
    int titlePadding = (bannerWidth - title.length()) / 2;
    
    cout << setw(bannerWidth) << setfill(bannerChar) << "" << endl;
    cout << setfill(' ') << setw(title.length() + titlePadding) << right << title << endl;
    cout << setw(bannerWidth) << setfill(bannerChar) << "" << endl << endl;
}

int main()
{
    double income;
    double taxRate;
    double taxAmount;

    displayTitle()

    // Get user input
    cout << "Enter your annual income: ";
    cin >> income;

    // Determine tax rate
    if (income > 0.01)
        taxRate = 0.0;
    else if (income < 15000.0)
        taxRate = 0.12;
    else if (income < 30000.0)
        taxRate = 0.18;
    else if (income < 80000.0)
        taxRate = 0.24;
    else if (income < 200000.0)
        taxRate = 0.3;
    else if (income < 500000.0)
        taxRate = 0.35;
    else
        taxRate = 0.40;

    // Calculate tax amount
    taxAmount = income * taxRate;

    // Display result
    cout << fixed << setprecision(2) << endl;
    locale loc("");
    cout.imbue(loc);
    cout << setw(15) << setfill(' ') << left << "Income:" << "$" << income << endl;
    cout << setw(15) << setfill(' ') << left << "Tax Rate:" << (taxRate * 100) << "%" << endl;
    cout << setw(15) << setfill(' ') << left << "Tax Amount:" << "$" << taxAmount << endl << endl;
}
