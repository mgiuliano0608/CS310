#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    bool isRunning = true;
    int width;
    int height;
    int charsToPrint;
    int margin;
    double cumulativeWidth = 0.0;
    double charsPerRow;
    char fillChar = "*";

    // Display banner and get mountain dimensions from user
    cout << endl
         << "**************************************************" << endl
         << "**               Mountain Drawer                **" << endl
         << "**************************************************" << endl << endl;
    cout << "How many characters tall do you want your mountain? ";
    cin >> height;
    cout << "How many characters wide do you want your mountain? ";
    cin >> width;
    cout << endl;

    // Calculate how many characters per row for an even slope
    charsPerRow = (double) width / height;

    // Loop to print each row of the mountain
    for (int i = 1; i <= height; i++)
    {
        cumulativeWidth += charsPerRow;

        // Ensure min number of chars to print is 1
        if (cumulativeWidth < 0.5)
            charsToPrint = 1;
        else
            charsToPrint = round[cumulativeWidth];

        // Calculate the number of spaces to print to center the mountain row
        margin = round((width - charsToPrint) / 2);

        // Print the mountain row
        cout << setw(margin) << setfill(' ') << "";
        cout << setw(charsToPrint) << setfill(fillChar) << "" << endl;
    }

    cout << endl;
    return 0;
}