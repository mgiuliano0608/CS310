#include <iostream>

using namespace std;

enum grades {A, B, C, D};

int main()
{
  grades myGrade = B;
  
  if (myGrade == A) {
    cout << "Congrats!  You've got an A!";
      }
  else if (myGrade == B) {
    cout << "Nice Job!  You have a B!";
  }
  else if (myGrade == C) {
    cout << "You have a C!";
  }
  else if (myGrade == D) {
    cout << "You have a D.";
  }
  else {
    cout << "You are not currently passing.  Keep working and you'll get there in no time at all!";
  }

  return 0;
}