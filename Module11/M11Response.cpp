#include <iostream>
#include <random>

using namespace std;

template <typename T>
void multiply(T a, T b)
{
	T result = a * b;

	cout << "\nMultiplying " << a << " and " << b << " Results in : " << result << endl;

	if (result > 0)
	{
		cout << "This is a positive number." << endl;
	}
	else
	{
		cout << "This is a negative number." << endl;
	}
}

int main()
{
	random_device rdevice;
	default_random_engine magicNumber(rdevice());

	uniform_int_distribution<int> distribution(-100, 100);

	int number1 = distribution(magicNumber);
	int number2 = distribution(magicNumber);

	cout << "The magic numbers are: " << number1 << " and " << number2 << endl;

	multiply(number1, number2);

	cout << "\nPress any key to continue..." << endl;

	return 0;
}