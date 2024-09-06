#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    string name;
    double sideA, sideB, hypotenuse;
    double radius, circumference;
    
    // Greeting
    cout << endl << "--------------------------------------------------" << endl;
    cout << "What is your first name? ";
    cin >> name;
    cout << endl << "Hello " << name << "!" << endl;
    
    // Calculate the hypotenuse of a right triangle
    cout << endl << "Lets calculate the hypotenuse of a right triangle." << endl;
    cout << "Enter the length of side a: ";
    cin >> sideA;
    cout << "Now enter the length of side b: ";
    cin >> sideB;
    hypotenuse = sqrt(pow(sideA, 2) + pow(sideB, 2);
    cout << fixed << setprecision(2);
    cout << "The hypotenuse of a right triangle with sides " << sideA << " and ";
         << sideB << " is " << hypotenuse << endl;

    // Calculate the circumference of a circle
    cout << endl << "Great! Now lets calculate the circumference of a circle." << endl;
    cout << "Enter the circle's radius: ";
    cin << radius;
    circumference = 2 x M_PI x radius;
    cout << "The circumference of a circle with a radius of " << radius << " is " << circumference << endl;

    cout << "Thank you for using this app! Have a great day!" << endl;
    cout << endl << "--------------------------------------------------" << endl;
    return 0;
}