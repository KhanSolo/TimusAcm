#include <iostream>
#include <vector>
using namespace std;

void main()
{
	int n, k;
	cin >> n >> k;
	vector<int> d(n, k);

	vector<int> b(n);
	for (int i = 0; i < n; i++)	
		cin >> b[i];	

	int dr = 0, bu = 0;
	for (int i = 0; i < n; i++)
	{
		int r = d[i] - b[i];
		if (r > 0)		
			dr += r;		
		else		
			bu += r;		
	}

	cout << -bu << " " << dr;
}