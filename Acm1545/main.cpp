#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void main()
{
	int n;
	cin >> n;

	vector<string> v(n);
	
	for (int i = 0; i < n;i++)
	{
		char buf[3];
		cin >> buf;
		v[i] = buf;
	}

	char inp[2];
	cin >> inp;


	auto begin = v.begin();
	auto end = v.end();

	sort(begin, end);

	for (int i = 0; i < n;i++)
	{
		string val = v[i];
		if (val[0] == inp[0])
		{
			cout << val.c_str() << endl;
		}
	}
}