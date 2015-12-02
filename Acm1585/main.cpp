#include <iostream>
#include <map>
#include <string>
using namespace std;

void main()
{
	int n;	cin >> n;

	string zlo;	getline(cin, zlo);

	map<string, int> penguins;
	
	for (int i = 0; i < n; i++)
	{
		string str;		getline(cin, str);
		++penguins[str];
	}

	int max = 0;
	const string * name = nullptr;
	auto it = penguins.begin();
	while (it != penguins.end())
	{
		if (it->second > max)
		{
			max = it->second;
			name = &(it->first);
		}
		++it;
	}

	cout << *name;
}