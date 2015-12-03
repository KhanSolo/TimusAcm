#include <iostream>
#include <iomanip>

using namespace std;

void main()
{
	int n; 	cin >> n;

	long double distance = 0.0;
	for (int i = 0; i < n; i++)
	{
		long double x, y;
		cin >> x >> y;

		long double d = sqrt(x*x + y*y);
		if (d > distance)
			distance = d;
	}
	cout << fixed << setprecision(14);
	// 1,41421356237309
	cout << "0 0 " << distance;
}