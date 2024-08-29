//*********************************************************
// Michael Giuliano
// CS310-T301
// M1: Assignment 1.2
//*********************************************************

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    float originalPrice;
    float markupPercentage;
    float salesTaxPercentage;

    // Get user input
    cout << "Enter the original price (Ex. 200.00): ";
    cin >> originalPrice;
    cout << "Enter the markup percentage (Ex. 20.0): ";
    cin >> markupPercentage;
    cout << "Enter the sales tax percentage (Ex. 6.0): ";
    cin >> salesTaxPercentage;

    // Calculate product values
    float markupRate = markupPercentage / 100;
    float salePrice = originalPrice * (1 + markupRate);
    float salesTaxRate = salesTaxPercentage / 100;
    float salesTax = salePrice * salesTaxRate;
    float totalPrice = salePrice + salesTax;

    // Output results
    cout << endl << fixed << setprecision(2);
    cout << "Original price: $" << originalPrice << endl;
    cout << "Markup percentage: " << markupPercentage << "%" << endl;
    cout << "Sale price: $" << salePrice << endl;
    cout << "Sales tax rate: " << salesTaxPercentage << "%" << endl;
    cout << "Sales tax: $" << salesTax << endl;
    cout << "Total price: $" << totalPrice << endl;

    return 0;
}