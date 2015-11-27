#include <iostream>

using namespace std;

void main()
{
	int a, b;

	cin >> a;
	cin >> b;
	if (a > 0 && b > 0)
	{
		int total = a + b - 1;

		int a1 = total - b;
		int b1 = total - a;
		a = a1;
		b = b1;
	}
	cout << b << " " << a;
}