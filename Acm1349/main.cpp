/*

Для целых чисел n больше 2 уравнение x^n + y^n = z^n не имеет ненулевых решений в натуральных числах.

*/

#include <iostream>

using namespace std;

int main(){

	int n;
	cin >> n;
	
	if (n > 2 || 0 == n)
	{
		cout << "-1";
		return 0;
	}

	if (1 == n)
	{
		cout << "1 2 3";
		return 0;
	}

	// n == 2
	cout << "3 4 5";


	return 0;
}