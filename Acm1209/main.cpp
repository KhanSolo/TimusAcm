#include <iostream>
#include <vector>
using namespace std;

typedef long long uint; // long long, ò.ê. 8*ki 

// 2^31 - 1 = 2147483647

// 65536 * 65535 / 2 + 1 = 2147450881

// 2147450881  => d = 17179607041 => sqrt = 131071 

void main()
{
	int n; 
	cin >> n;

	vector<uint> k(n);

	for (int i = 0; i < n; i++) cin >> k[i];		
	
	for (int i = 0; i < n; i++)
	{
		uint ki = k[i];

		// x(x-1) / 2 + 1 = ki;
		// x = (-1 + sqrt(1-8(1-ki))) / 2;

		uint d = 1 - 8 * (1 - ki); // discriminant
		
		uint sq = (uint)sqrt(d);

		if(sq*sq == d)
			cout << 1 << " ";
		else
			cout << 0 << " ";
	}
}