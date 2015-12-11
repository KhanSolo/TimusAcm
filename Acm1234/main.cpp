#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long double dbl;

int main()
{
	vector<dbl> v1(3);

	cin >> v1[0] >> v1[1] >> v1[2];
	dbl d, e;
	cin >> d >> e;
	if (d > e)
	{
		dbl temp = d;
		d = e;
		e = temp;
	}

	sort(v1.begin(), v1.end());
	dbl a = v1[0];
	dbl b = v1[1];

	dbl epsilon = 10e-9;

	if ((d-a)<=epsilon && (e-b)<=epsilon)
	{
		cout << "YES";
		return 0;
	}


	// diag
	dbl hyp = sqrtl(d*d + e*e);

	dbl sin_phy = d / hyp;
	dbl cos_phy = e / hyp;
	
	dbl x = b*sin_phy + a*cos_phy;
	dbl y = b*cos_phy + a*sin_phy;

	if (x <= d && y <= e)
	{
		cout << "YES";
		return 0;
	}
	cout << "NO";
	return 0;
}