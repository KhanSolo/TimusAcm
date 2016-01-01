/*
so we have
f'(x) = k(2x - (2/n)(a1 + a2 + ... + an))
setting to zero and solving for x gives

x = (a1 + a2 + ... + an) / n
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int n; cin >> n;
	double s = 0.0;
	for (int i = 0; i < n;i++)
	{
		double inp;
		cin >> inp;
		s += inp;
	}
	double result = s / n;

	cout << fixed << setprecision(6);
	cout << result;
	return 0;
}