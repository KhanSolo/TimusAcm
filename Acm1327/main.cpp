#include <iostream>
using namespace std;

void main()
{
	int a, b, res;
	cin >> a >> b;

	if ((a & 1) == 0) a++;
	if ((b & 1) == 0) b--;

	res = (b - a) / 2 + 1;

	cout << res;
}