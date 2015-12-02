#include <iostream>
#include <map>
#include <string>
using namespace std;

void main()
{
	int n;	cin >> n;
	string zlo;	getline(cin, zlo);

	map<string, int> accounts;

	for (int i = 0; i < n; i++)
	{
		string str;		getline(cin, str);
		++accounts[str];
	}

	auto it = accounts.begin();
	while (it != accounts.end())
	{
		if (it->second > 1)
		{
			cout << it->first << endl;
		}
		++it;
	}
}