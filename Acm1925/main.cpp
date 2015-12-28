#include <iostream>

using namespace std;

int main()
{
	int n, k;	
	cin >> n >> k;

	int sum1 = 0;
	int sum2 = 0;

	for (int i = 0; i < n; i++)
	{		
		int b, g;
		cin >> b >> g;

		sum1 += b;
		sum2 += g;
	}

	int x = sum1 + k - (n + 1) * 2 - sum2;

	if (x >= 0)	cout << x;
	else		cout << "Big Bang!";

	return 0;
}