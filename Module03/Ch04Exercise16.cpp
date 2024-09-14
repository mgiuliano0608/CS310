#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double netPricePerCopy;
    int numberOfCopies;

    // Get input from user
    cout << endl << "-------------------------------------------------" << endl;
    cout << "           BOOK ROYALTY CALCULATOR";
    cout << endl << "-------------------------------------------------" << endl << endl;
    cout << "What is the net price of each copy? ";
    cin >> netPricePerCopy;
    cout << "How many copies are sold? ";
    cin >> numberOfCopies;
    
    // Calculate option A
    double manuscriptPayment = 5000.0;
    double publishingPayment = 20000.0;
    double optionANetRoyalties = manuscriptPayment + publishingPayment;

    // Calculate option B
    double optBRoyaltyRate = 0.125;
    double optionBNetRoyalties = netPricePerCopy * numberOfCopies * optBRoyaltyRate;
    
    // Calculate option C
    double optCRoyaltyRate1 = 0.1;
    double optCRoyaltyRate2 = 0.14;
    double optionCNetRoyalties = 0.0;
    int adjustedCopies;
    if (numberOfCopies <= 4000)
        optionCNetRoyalties += numberOfCopies * netPricePerCopy * optCRoyaltyRate1;
    else
    {
        optionCNetRoyalties += 4000 * netPricePerCopy * optCRoyaltyRate1;
        adjustedCopies = numberOfCopies - 4000;
        optionCNetRoyalties += adjustedCopies * netPricePerCopy * optCRoyaltyRate2;
    }

    // Determine best option
    char bestOption = 'A';
    double bestOptionAmount = optionANetRoyalties;
    if (optionBNetRoyalties > bestOptionAmount)
    {
        bestOption = 'B';
        bestOptionAmount = optionBNetRoyalties;
    }
    if (optionCNetRoyalties > bestOptionAmount)
    {
        bestOption = 'C';
        bestOptionAmount = optionCNetRoyalties;
    }

    // Display options
    cout << fixed << setprecision(2);
    locale loc("");
    cout.imbue(loc);
    cout << endl << "NET ROYALTIES" << endl << "_____________";
    cout << endl << "Options A: $" << optionANetRoyalties;
    if (bestOption == 'A') cout << " (best option)";
    cout << endl << "Options B: $" << optionBNetRoyalties;
    if (bestOption == 'B') cout << " (best option)";
    cout << endl << "Options C: $" << optionCNetRoyalties;
    if (bestOption == 'C') cout << " (best option)";
    cout << endl << endl;
}