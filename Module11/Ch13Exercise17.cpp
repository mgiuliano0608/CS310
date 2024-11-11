#include <iostream>
#include <random>

using namespace std;

int main() {
    random_device device{};
    default_random_engine num{ device() };
    uniform_int_distribution<unsigned int> randomNum(10, 100);

    cout << endl << "25 Random Numbers from 1 to 100" << endl
         << "-------------------------------" << endl;

    for (int i = 1; i <= 25; i++) {
        cout << i << ") " << randomNum(num) << endl;
    }

    cout << endl;

    return 0;
}