#include <iostream>
#include <string>

using namespace std;

bool isVowel(char c);
string removeVowels(string str);

int main() {
    string text = "";
    string newText = "";

    cout << endl
        << "**************************************************" << endl
        << "**               VOWEL REMOVER                  **" << endl
        << "**************************************************" << endl << endl;

    cout << "Enter a string to remove the vowels: ";
    cin >> text;

    newText = removeVowels(text);

    cout << endl << "Original String: " + text << endl;
    cout << "String without vowels: " + newText << endl << endl;
}

// Determines if a character is a vowel in either upper or lowercase
bool isVowel(const char c) {
    char vowels[] = { 'A', 'a', 'E', 'e', 'I', 'i', 'O', 'o', 'U', 'u' };

    for (char vowel : vowels) {
        if (c == vowel)
            return true;
    }

    return false;
}

// Removes all vowels from a string and return the new string
string removeVowels(const string str) {
    string newStr = "";

    for (char c : str) {
        if (!isVowel(c))
            newStr.push_back(c);
    }

    return newStr;
}