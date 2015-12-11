#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

typedef long double dbl; // sizeof(double) == sizeof(long double)

string GetAnswer(dbl a, dbl b, dbl c, dbl d, dbl e)
{
	//a *= 10.0;
	//b *= 10.0;
	//c *= 10.0;
	//d *= 10.0;
	//e *= 10.0;

	dbl epsilon = 10e-9; // accuracy
	
	if (a<(d + epsilon)
		&& 
		b<(e+epsilon))
	{		
		return "YES";
	}

	/*
	// diagonal angle - phy
	dbl hyp = sqrtl(d*d + e*e);

	dbl sin_phy = d / hyp;
	dbl cos_phy = e / hyp;


	dbl x = b*sin_phy + a*cos_phy; // (b * d + a * e) / sqrtl(d*d + e*e)
	dbl y = b*cos_phy + a*sin_phy; // (b * e + a * d) / sqrtl(d*d + e*e)
	*/

	dbl x2 = (b * d + a * e)*(b * d + a * e) / (d*d + e*e); // (b*b*d*d + 2*b*d*a*e + a*a*e*e)
	dbl y2 = (b * e + a * d)*(b * e + a * d) / (d*d + e*e);

	//if (x <= d && y <= e)
	if (x2 < (d*d + epsilon) && y2 < (e*e + epsilon))
	{		
		return "YES";
	}
	return "NO";
}

void swap(dbl&a, dbl&b) { dbl temp = a; a = b; b = temp; }

int main()
{	
	_ASSERT(GetAnswer(1.0, 1.5, 2.0, 1.0, 1.4) == "NO");	
	_ASSERT(GetAnswer(1.0, 1.5, 2.0, 1.0, 1.5) == "YES");	
	_ASSERT(GetAnswer(1.0, 10, 10, 6.0, 9.0) == "NO");
	_ASSERT(GetAnswer(1.0, 10, 10, 7.0, 9.0) == "YES");
	_ASSERT(GetAnswer(1.5, 2.9, 10.0, 1.4, 10.0) == "NO");
	//---
	
	vector<dbl> v1(3);

	cin >> v1[0] >> v1[1] >> v1[2];
	dbl d, e;
	cin >> d >> e;
	if (d > e) swap(d, e);


	sort(v1.begin(), v1.end());
	dbl a = v1[0];
	dbl b = v1[1];

	string answer = GetAnswer(a, b, 0.0, d, e);

	cout << answer;

	return 0;
}