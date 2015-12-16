#include<iostream>
#include <vector>
#include <map>
using namespace std;

void main()
{
	int n;
	cin >> n;

	map<int, vector<int> *> m;

	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;

		auto m_it = m.find(b);
		if (m_it != m.end())
		{			
			auto vec = m_it->second;
			vec->push_back(a);
		}
		else
		{
			vector<int> * vec = new vector<int>();
			(* vec).push_back(a);
			m[b] = (vec);
		}
	}

	for (auto itr = m.rbegin(); itr != m.rend(); itr++)
	{
		auto vec = itr->second;
		int sz = vec->size();

		for (int i = 0; i < sz; i++)
		{
			cout << (*vec)[i] << " " << itr->first << endl;
		}	
		delete vec;
	}
}