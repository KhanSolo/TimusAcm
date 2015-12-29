#include <iostream>
#include <vector>

using namespace std;

int main()
{
	unsigned long n;
	cin >> n;
	
	//---
	if (0 == n)
	{
		cout << "10" << endl;
		return 0;
	}

	if (1 == n)
	{
		cout << "1" << endl;
		return 0;
	}
	//---


	vector<int> v;
	for (int i = 9; i>1; i--)
	{
		while (n%i == 0)
		{			
			v.push_back(i);
			n /= i;
		}
	}

	if (n != 1)							
		cout << "-1";			
	else 
	{
		auto sz = v.size()-1;
		for (int i = sz; i >= 0; i--)
			cout << v[i];
	}
	return 0;
}