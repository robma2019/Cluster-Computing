#include <iostream>
using namespace std;
int main()
{
	int num1, ctr = 0;
	cout << "\n\n Check whether a number is prime or not:\n";
	cout << "--------------------------------------------\n";
	cout << " Input a number to check prime or not: ";
	cin >> num1;

	for (int a = 1; a <= num1; a++)
	{	// checking if the input numbers remainder is 0
		// if it is then inc ctr.
		// so it is true for every case, for example 7 / 1 = 7 remainder of 0
		// so then inc ctr
		if (num1 % a == 0)
		{
			ctr++;
		}
	}
	if (ctr == 2)
	{
		cout << " The entered number" << num1 << "is a prime number. \n";
	}
	else {
		cout << " The number you entered is not a prime number. \n";
	}

	system("pause");
}
