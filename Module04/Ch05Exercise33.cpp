#include <iostream>

using namespace std;

int main()
{
    int a;  // Number of minutes to prepare the first dish
    int b;  // extra time for other dishes compared to its previous dish
    int t;  // time to prepare the dishes
    int dishCount = 0;
    int totalTime;
    int increment;

    // Get input values from user
    cout << endl << "How many minutes does it take Bianca to prepare the first dish? ";
    cin >> a;
    cout << "How many minutes longer does it take to prepare each additional dish from its previous dish? ";
    cin >> b;
    cout << "How many minutes does Bianca have to prepare dishes? ";
    cin >> t;

    // Calculate how many dishes Bianca can prepare in the given time.
    totalTime = a;
    increment = a + b;
    while (totalTime <= t)
    {
        ++dishCount;
        totalTime += increment;
        increment += b;
    }

    // Display result
    printf("\nIn %d minute(s), Bianca can prepare %d dish(es).\n\n", t, dishCount);

    return 0;
}