#include <iostream>

using namespace std;

void display2DArray(int arr[3][3]);

int main() {
    
    // Matrix A
    int a[3][3] = 
        {1, 0, 0},
        {0, 1, 1},
        {1, 1, 0};

    // Matrix B
    int b[3][3] = 
        {1, 1, 1},
        {1, 0, 1},
        {0, 1, 1};

    // XOR the elements of Matrix A with Matrix B
    int result[][];
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            result[row][col] = a[row][col] ^ b[row][col];
        }
    }

    cout << endl << "Matrix A" << endl;
    display2DArray(a);
    cout << endl << "Matrix B" << endl;
    display2DArray(b);
    cout << endl << "Matrix A XOR Matrix B" << endl;
    display2DArray(result);
}

// Displays the elements of a 2D array
void display2DArray(int arr[3][3]) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            cout << arr[row][col] << " ";
        }
        cout << endl;
    }
}