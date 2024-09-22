#include <iostream>
#include <cstdlib>

using namespace std;  // Changed from "standard" to std

int main() {
    // Generates random seed so the rand() function can select a random number each time, the error isn't here
    srand((unsigned) time(NULL)); 
    int target = rand() % 100;
    int guess;

    cout << "Guess a number, 0 through 100. Enter '-1' to quit. \n" << endl;

    while (guess != target) {

        cin >> guess;
        if (guess == target || guess == -1) {  // Logic error. changed to 'guess == -1'
            break;
        }
        else if (guess < 0 || guess > 100) {
            cout << "Your guess should be between 1 and 100. \n" << endl;
        }
        else if (guess > target) {
            cout << "That guess is too high. Try again! \n" << endl;
        }
        else if (guess < target) {
            cout << "That guess is too low. Try again! \n" << endl;
        }
    }
    
    cout << endl;
    if (guess == target) {
        cout << "Congratulations, you correctly guessed the number " << target << "!" << endl;
    }
    else {
        cout << "Nice try, the correct number was " << target << "!" << endl;
    }

    return 0;        
}