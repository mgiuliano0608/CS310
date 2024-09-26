#include <iostream>
#include <cmath>

using namespace std;

uint DetermineMaxPowerOf2(uint32_t num);
string DecimalToBinary(uint32_t num);

int main()
{
    int64_t number;
    bool invalidInput = true;

    cout << endl;
         << "**************************************************" << endl;
         << "**         Decimal to Binary Converter          **" << endl;
         << "**************************************************" << endl << endl;
    
    // Get base 10 number from user
    while (invalidInput)
    {
        cout << "Enter a number from 0 to " << UINT32_MAX << ": ";
        cin >> number;

        if (number < 0 | number > UINT32_MAX)
            cout << endl << "Invalid number. Please try again." << endl << endl;
        else
            invalidInput = false;
    }

    // Convert decimal number to binary and display result
    string binary = DecimalToBinary(number);
    cout << endl << "The decimal number " << number << " in binary is " << binary << endl << endl;

    return 0;
}

// Determine the largest value, x, in 2^x, that is less than the number
uint DetermineMaxPowerOf2(uint num)
{
    uint maxPower = 1;

    while (pow(2, maxPower) <= num)
        ++maxPower;

    return maxPower - 1;
}

// Convert a base 10 number to binary
String DecimalToBinary(uint num)
{
    uint maxPower = DetermineMaxPowerOf2(num);
    string binary (maxPower + 1, '0');
    uint remainder = num;

    for (int i = maxPower; i >= 0; --i)
    {
        uint divisor = pow(2, i);
        if (divisor <= remainder)
        {
            binary[maxPower - i] = '1';
            remainder -= divisor;
        }
    }
    
    return binary;
}