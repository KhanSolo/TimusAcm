#include <iostream>
using namespace std;

void main()
{
	int k, n;

	cin >> k >> n;

	int res = 0;
	for (int i = 0; i < n; i++)
	{
		int inp;
		cin >> inp;
		res += inp;
		res -= k;
		if (res < 0) res = 0;
	}

	cout << res;
}