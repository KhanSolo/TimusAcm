#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int x, y, c;
	cin >> x >> y >> c;

	if (c-x>y)
	{
		cout << "Impossible";
	}
	else
	{
		int a = min(x, c);
		cout << a << " " << c - a;
	}

	return 0;
}