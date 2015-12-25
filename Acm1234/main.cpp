#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

typedef long double dbl;
typedef long long lng;

const dbl PI = 3.14159265359;

bool TryWithCalc(lng a, lng b, lng d, lng e)
{
	int max_angle = 47;
	max_angle++;

	int parts = 10000;
	dbl step = ((dbl)max_angle*PI/180) / parts;
	
	bool result = false;

	for (int i = 0; i <= parts; i++)
	{
		dbl rad = i * step;
		auto si = sin(rad);
		auto co = cos(rad);

		auto w = (dbl)b*co + (dbl)a*si;
		auto h = (dbl)b*si + (dbl)a*co;

		if ((dbl)d >= h && (dbl)e >= w)
		{
			result = true;
			break;
		}
	}
	return result;	
}

string GetAnswer(lng a, lng b, lng d, lng e)
{	
	if (a<=d && b<=e)
	{
		return "YES";
	}
	
	// просовывает не строго по диагонали
	if (true == TryWithCalc(a, b, d, e))
		return "YES";

	return "NO";
}


int main() 
{	
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
	
	_ASSERT(GetAnswer(10, 99, 60, 90) == "YES"); 

	//---

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