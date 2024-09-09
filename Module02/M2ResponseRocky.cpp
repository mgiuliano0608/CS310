#include <iostream>  // Missing import
#include <string>    // Missing import

using namespace std;

int main() {
    string first_name;
    string last_name;

    cout << "Enter your first name: " ;
    cin >> first_name;  // angle brackets facing the wrong way

    cout << "Enter your last name: " ; 
    cin >> last_name;

    cout << "Hello, " << first_name + " " + last_name << endl; // No an error, but missing an endl
    
    return 0;
}