#include <iostream>
using namespace std;

int calc(int n, int k)
{
	int res = 0;

	if (n <= k)
	{
		res = 2;
	}
	else
	{
		int sides = n * 2;
		int a1 = sides / k; 
		int a2 = ((sides % k) > 1 ? 1 : 0);
		res = a1 + a2;
	}
	return res;
}

void main()
{
	//_ASSERT(calc(1, 2) == 2);
	//_ASSERT(calc(3, 2) == 3);
	//_ASSERT(calc(7, 4) == 4);


	int n, k;
	cin >> n >> k;
	
	int res = calc(n, k);

	cout << res;
}