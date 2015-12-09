#include <iostream>
#include <map>
#include <vector>
using namespace std;

typedef unsigned int uint;

void main()
{
	int n; cin >> n;

	vector<uint> k(n);

	for (int i = 0; i < n; i++)
	{
		uint ki; 
		cin >> ki;
		k[i] = ki;
	}

	map<uint, int> m;

	uint limit = 2147483647; // 2^31 - 1 
	for (uint i = 1; i <= limit; i++)
	{
		uint c = (i - 1)*i / 2 + 1;
		m[c] = 1;
		//m.insert();
	}

	for (int i = 0; i < n; i++)
	{
		if (m.count(k[i]))
			cout << 1 << " ";
		else
			cout << 0 << " ";
	}

}