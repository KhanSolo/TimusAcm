/*
Утро сороконожки
*/
#include <iostream>

using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;

	int l = b * 2 + 40;
	int r = 40 + 39 * 2 + (a - 40) * 2 + 1;

	cout << ((l >= r) ? l : r);

	return 0;
}