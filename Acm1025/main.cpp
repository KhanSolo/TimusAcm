#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void main()
{
	int n;
	cin >> n;

	vector<int> g(n);

	for (int i = 0; i < n; i++) cin >> g[i];
	
	std::sort(g.begin(), g.end());

	int gmid = n / 2;

	int sum = 0;
	for (int i = 0; i <= gmid; i++)
	{
		int p = g[i];
		int pmid = p / 2 + 1;
		sum += pmid;
	}

	cout << sum;
}