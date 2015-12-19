/*

m = f(n) = f(n-1)  + f(n-2)

why f(n-1) :-
put W and [R,...(n-1)] or R and [W,...(n-1)]

why f(n-2) :-
put R,B and [W,..(n-2)] or W,B and [R,...(n-2)]

*/
#include <iostream>

using namespace std;

typedef unsigned long ulong;

int main()
{
	ulong m;	cin >> m;

	ulong a = 1, b = 1;

	for (ulong i = 1; i < m; ++i)
	{
		ulong temp(a);
		a = a + b;
		b = temp;

		//cout << " a : " << a << " b : " << b << endl;
	}
		
	cout << b * 2;
	
	return 0;
}