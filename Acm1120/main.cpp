#include <iostream>

// acm timus 1120

void main()
{
	int n,a,p;
	std::cin >> n;
	
	int p1 = 0, a1 = 0;

	// корень кв уравнения P : (A+P-1)(A+P) = 2N
	int lim = 44721;
	for (p = 1; p < lim; p++)
	{		
		int zp = (2 * n) % p;
		if (zp > 0) continue;
		
		int za = (2 * n / p - p + 1) % 2;
		if (za > 0) continue;

		a = (2 * n / p -  p + 1) >> 1;
		
		if (a <= 0) continue;
		if (p > p1)
		{
			p1 = p;
			a1 = a;
		}
	}

	std::cout << a1 << " " << p1 ;
}