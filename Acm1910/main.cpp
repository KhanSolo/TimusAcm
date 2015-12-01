#include <iostream>
#include <vector>
using namespace std;

void main()
{
	int n;
	cin >> n;

	vector<int> v;
	v.resize(n);

	for (int i = 0; i < n; i++)	
		cin >> v[i];
	
	int max = 0, 
		store = -1;
	for (int i = 1; i < n-1; i++)
	{
		// 3 подряд
		int v1 = v[i - 1];
		int vi = v[i];
		int v2 = v[i + 1];
		
		if (v1 + vi + v2 > max)
		{
			max = v1 + vi + v2;
			store = i;
		}		
	}

	cout << max << " " << ++store << endl;
}