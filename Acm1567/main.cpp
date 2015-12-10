#include <iostream>
#include <map>
#include <string>
using namespace std;

void main()
{
	string str;
	getline(cin, str);

	map<char, int> c;

	int val = 0;
	for (char cc = 'a'; cc <= 'z'; cc++)
	{
		c[cc] = ++val;
		if (3 == val) val = 0;
	}
	c['.'] = 1;
	c[','] = 2;
	c['!'] = 3;
	c[' '] = 1;


	int cost = 0;
	int size = str.size();

	for (int i = 0; i < str.size(); i++)
	{
		char ch = str[i];
		cost += c[ch];
	}

	cout << cost;
}