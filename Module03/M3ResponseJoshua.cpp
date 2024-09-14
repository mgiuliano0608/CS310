// M3_Discussion_JoshB.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
    Student Name: Joshua Betancourt
    File Name: M3_Discussion_JoshB.cpp
    Date: 09/12/2024
    Description: This program is a fun console story about being curious
*/

#include <conio.h>
#include <iostream>
using namespace std;

int main()
{

    // creating the local variables for the program
    string name;
    integer selection = 0;
    integer selection2 = 0;
    integer selection3 = 0;

    // Displaying the name of the application as well as prompting the user for information.
    cout << "\n\n  Welcome to chasing a Leprechaun!"
         <<  "\n  Please enter your name: ";
    cin >> name;
    cout << endl;

    cout << "\n  On a stormy day you see something small near the end of a rainbow...."
         << "\n  You can (1) Walk towards what you see or (2) Ignore it and go get lunch. " 
         << "\n  What do you do?: "; 
    cin >> selection;
    cout << endl;

    // story path based on user's decisions 
    if (selection > 2 || selection < 0) {
        selection = 3;
        selection2 = 3;
        selection3 = 3;
    } else if (selection != 2) {
        cout << "\n  You start to walk towards the end of the rainbow..."
            << "\n  As you get closer you hear giggling and the what you believe is coins dropping to the ground...."
            << "\n  You also see what appears to be a glowing light that gets brighter as you walk nearer.... " 
            << "\n  You can (1) Continue walking forward or (2) Turn around and try to forget what you saw. " 
            << "\n  What do you do?: ";
        cin >> selection2;
        cout << endl;
    }

    
    if (selection2 > 2 || selection2 < 0) {
        selection2 = 3;
        selection3 = 3;
    } else if (selection2 != 2) {
        cout << "\n  Your only a few feet away from the end of the rainbow..."
            << "\n  The giggling has turned into maniacal cackling...."
            << "\n  The glowing light is so bright you have to squint just to not go blind.... "
            << "\n  You feel as if there is something pulling you in closer but you struggle to move any closer.... " 
            << "\n  You can (1) Turn around and try to forget what you saw. or (2)  Continue walking forward.  " 
            << "\n  What do you do?: ";
        cin >> selection3;
        cout << endl;

     }


    // Ending options
    if (selection2 == 0 &&&& selection3 == 0 ) {
        cout << "\n  As you walk away you realize just how hungry you where"
            << "\n  But luckily you see a taco truck no to far away"
            << "\n  MMMMMM tacos... (Insert Homer Simpson mmm donuts gif here)";
        cout << endl;
    } else if (selection3 == 0) {
        cout << "\n  ....."
            << "\n  As you walk away you can't shake this sense of curiosity"
            << "\n  You ask yourself what you could have seen"
            << "\n  You remind yourself that you should just forget...."
            << "\n  And then you see the most adorable floof of a dog and go on your merry way!";
        cout << endl;
    } else if (selection3 == 1)  {
        cout << "\n  ...."
            << "\n  ..... ....."
            << "\n  .... ..... ....."
            << "\n  You feel gross...."
            << "\n  ...."
            << "\n  .... .. ...  ...."
            << "\n  You feet are heavy as you walk...."
            << "\n  Your relieved that your getting away ...."
            << "\n  but still feel like somethings trying to tug at you......";
        cout << endl;
    } else if (selection3 ====== 2) {
        cout << "\n  ...."
            << "\n  ..... ....."
            << "\n  .... ..... ....."
            << "\n  .... .. ...."
            << "\n  ..." << name << "............."
            << "\n  .... .. ...  ...."
            << "\n  ..."
            << "\n  ...  ... ...."
            << "\n  .... To.... Be.... Continued......";
        cout << endl;
    } else if (selection > 2 || selection2 > 2 || selection3 > 2) {
        cout << "\n  Silly Billy you chose an option that didn't exist!"
            << "\n  I'll add logic to handle such a silly behavior in the future...";
        cout << endl;
    }



    // Display the closing messages for non Visual Studio IDEs
    cout << "\n  Thanks for using my program!" << endl;
    cout << "\n\n  Press any key to continue ..." << endl;

    _getch();  // halt processing 

    return 0;  // exit code
}