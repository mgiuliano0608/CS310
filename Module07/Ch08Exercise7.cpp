#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int calculateWinner();
void displayResults(int winner);

const int NUM_RECORDS = 5;
string candidates[NUM_RECORDS];
int votes[NUM_RECORDS];
float percentages[NUM_RECORDS];

int main() {
    cout << endl
        << "**************************************************" << endl
        << "**          ELECTION RESULT CALCULATOR          **" << endl
        << "**************************************************" << endl << endl;

    cout << "Enter the candidate's last name and his/her number of votes (ex. Washington 125000)" << endl;
    for (int i = 0; i < NUM_RECORDS; i++) {
        cout << "Candidate " << (i + 1) << ": ";
        cin >> candidates[i];
        cin >> votes[i];
    }
    cout << endl;
    
    int winner = calculateWinner();
    displayResults(winner);

    return 0;
}

// Calculates the percentage of total votes for each candidate and returns
// the index of the candidate with the largest number of votes.
int calculateWinner() {
    int votesSum = 0;
    int highest = 0;

    for (int amount : votes) {
        votesSum += amount;
    }

    for (int i = 0; i < NUM_RECORDS; i++) {
        percentages[i] = (float) votes[i] / votesSum * 100;
        if (votes[i] > votes[highest]) {
            highest = i;
        }
    }

    return highest;
}

// Displays a table containing each candidate's name, number of votes, and percentage of votes,
// as well as the winner with the largest number of votes.
void displayResults(int winner) {
    cout << fixed << setprecision(2);
    locale loc("");
    cout.imbue(loc);
    for (int i = 0; i < NUM_RECORDS; i++) {
        if (i == 0) {
            cout << setfill(' ') << setw(20) << left << "Candidate";
            cout << setfill(' ') << setw(20) << left << "Votes Received";
            cout << setfill(' ') << setw(20) << left << "% of Total Votes" << endl;
            cout << setfill('-') << setw(60) << "" << endl;
        }
        cout << setfill(' ') << setw(20) << left << candidates[i];
        cout << setfill(' ') << setw(20) << left << votes[i];
        cout << setfill(' ') << setw(20) << left << percentages[i] << endl;
    }

    cout << endl << "The Winner of the Election is " << candidates[winner] << "." << endl << endl;
}
