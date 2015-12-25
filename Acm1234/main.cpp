#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

typedef long double dbl;
typedef long long lng;

// angles not equal

string GetAnswer(lng a, lng b, lng d, lng e)
{	
	if (a<=d && b<=e)
	{
		return "YES";
	}
	
	//dbl x2 = (b * d + a * e)*(b * d + a * e) / (d*d + e*e); 
	//dbl y2 = (b * e + a * d)*(b * e + a * d) / (d*d + e*e); 

	// просовывает строго по диагонали
	if (
	 (d*d*(d*d + e*e) >= (b * d + a * e)*(b * d + a * e)) &&
	 (e*e*(d*d + e*e) >= (b * e + a * d)*(b * e + a * d))
	)
	//if (x2 <= (d*d) && y2 <= (e*e))
	{
		return "YES";
	}

	// просовывает не строго по диагонали
	// TODO !
	/*
	
	*/


	return "NO";
}

//string GetAnswer(dbl a, dbl b, dbl c, dbl d, dbl e)
//{
//	dbl epsilon = 10e-9; // accuracy
//	
//	if (a<(d + epsilon)
//		&& 
//		b<(e+epsilon))
//	{		
//		return "YES";
//	}
//
//	/*
//	// diagonal angle - phy
//	dbl hyp = sqrtl(d*d + e*e);
//
//	dbl sin_phy = d / hyp;
//	dbl cos_phy = e / hyp;
//
//
//	dbl x = b*sin_phy + a*cos_phy; // (b * d + a * e) / sqrtl(d*d + e*e)
//	dbl y = b*cos_phy + a*sin_phy; // (b * e + a * d) / sqrtl(d*d + e*e)
//	*/
//
//	dbl x2 = (b * d + a * e)*(b * d + a * e) / (d*d + e*e); // (b*b*d*d + 2*b*d*a*e + a*a*e*e) / (d*d + e*e)
//	dbl y2 = (b * e + a * d)*(b * e + a * d) / (d*d + e*e); // 
//
//	//if (x <= d && y <= e)
//	if (x2 < (d*d + epsilon) && y2 < (e*e + epsilon))
//	{		
//		return "YES";
//	}
//	return "NO";
//}

void swap(dbl&a, dbl&b) { dbl temp = a; a = b; b = temp; }
void swap(lng&a, lng&b) { lng temp = a; a = b; b = temp; }

int main() // still wa 16
{	
	//_ASSERT(GetAnswer(1.0, 1.0, 1.0, 1.0, 1.0) == "YES");
	//_ASSERT(GetAnswer(1.0, 1.5, 2.0, 1.0, 1.4) == "NO");	
	//_ASSERT(GetAnswer(1.0, 1.5, 2.0, 1.0, 1.5) == "YES");	
	//_ASSERT(GetAnswer(1.0, 10.0, 10.0, 6.0, 9.0) == "NO");
	//_ASSERT(GetAnswer(1.0, 10.0, 10.0, 7.0, 9.0) == "YES");
	//_ASSERT(GetAnswer(1.5, 2.9, 10.0, 1.4, 10.0) == "NO");
	//_ASSERT(GetAnswer(1.0, 10.0, 10.0, 9.0, 9.0) == "YES");
	//_ASSERT(GetAnswer(10.0, 10.0, 10.0, 10.0, 10.0) == "YES");
	//---

	_ASSERT(GetAnswer(10, 10, 10, 10) == "YES");
	_ASSERT(GetAnswer(10, 15, 10, 14) == "NO");
	_ASSERT(GetAnswer(10, 15, 10, 15) == "YES");
	_ASSERT(GetAnswer(10, 100, 60, 90) == "NO");
	_ASSERT(GetAnswer(10, 100, 70, 90) == "YES");
	_ASSERT(GetAnswer(15, 29, 14, 100) == "NO");
	_ASSERT(GetAnswer(10, 100, 90, 90) == "YES");
	_ASSERT(GetAnswer(100, 100, 100, 100) == "YES");

	// hole  = 8.8 (e) 6.6 (d)  diag angle 36,9 degrees
	// brick = 10.0 (b) 1.0 (a)
	_ASSERT(GetAnswer(10, 100, 66, 88) == "YES"); // впритирочку но не по диагонали (под углом 35 должно пройти)

	//---
	// pi = 3.141592654

	vector<dbl> v1(3);

	cin >> v1[0] >> v1[1] >> v1[2];
	dbl d, e;
	cin >> d >> e;
	if (d > e) swap(d, e);


	sort(v1.begin(), v1.end());
	dbl a = v1[0];
	dbl b = v1[1];

	string answer = GetAnswer(
		(lng)(10 * a), 
		(lng)(10 * b), 
		(lng)(10 * d), 
		(lng)(10 * e)
		);

	cout << answer;

	return 0;
}