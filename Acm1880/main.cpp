#include <iostream>
#include <map>
using namespace std;

void main()
{
	const int people = 3;
	map<int, int> m;

	for (int i = 0; i < people; i++)
	{
		int n;
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			int val;
			cin >> val;
			++m[val];
		}
	}


	map<int, int>::iterator m_iter = m.begin();
	int count = 0;
	while (m_iter != m.end())
	{		
		if (m_iter->second == people)
			++count;
		++m_iter;
	}

	cout << count;
}