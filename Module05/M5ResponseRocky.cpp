#include <iostream>
using namespace std;

bool is_palindrome (string& s) {
    int l = 0;
    int r = s.size() - 1;

    while (l < r) { 
        if (s[l] == s[r]) { 
            l++;
            r--;
        }
        else {
            return false;
        }
    }
    return true;  // Missing return statement
}

int main () {

    cout << "Enter a word: ";

    string input_string;
    cin >> input_string;

    if (is_palindrome(input_string) == true) {  // Missing argument in method call
        cout << input_string << " is a palindrome.";
    }
    else {
        cout << input_string << " is not a palindrome.";
    }

    return 0;
}