//
// Created by Javier on 10/31/2024.
//
#include <iostream>
using namespace std;

void add(double *a, double *b, double *result) {
    *result = *a + *b;
}

void subtract(double *a, double *b, double *result) {
    *result = *a - *b;
}

void multiply(double *a, double *b, double *result) {
    *result = *a * *b;
}

void divide(double *a, double *b, double *result) {
    if (*b != 0) {
        *result = *a / *b;
    } else {
        cout << "Error: Division by zero!" << endl;
    }
}

int main() {
    double num1, num2, result;
    char operation;

    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter an operator (+, -, *, /): ";
    cin >> operation;
    cout << "Enter second number: ";
    cin >> num2;

    double *ptr1 = &num1;
    double *ptr2 = &num2;
    double *ptrResult = &result;

    switch (operation) {
        case '+':
            add(ptr1, ptr2, ptrResult);
        cout << "Result: " << result << endl;
        break;
        case '-':
            subtract(ptr1, ptr2, ptrResult);
        cout << "Result: " << result << endl;
        break;
        case '*':
            multiply(ptr1, ptr2, ptrResult);
        cout << "Result: " << result << endl;
        break;
        case '/':
            divide(ptr1, ptr2, ptrResult);
        if (num2 != 0) {
            cout << "Result: " << result << endl;
        }
        break;
        default:
            cout << "Invalid operator!" << endl;
    }

    return 0;
}