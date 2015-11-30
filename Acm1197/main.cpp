#include <iostream>
#include <queue>
#include <string>
using namespace std;

void main()
{
	int board[8][8] = {2,3,};

	int n;
	cin >> n;

	queue<string> pos;

	for (int i = 0; i < n; i++)
	{
		string val;
		cin >> val;
		pos.push(val);
	}

	while(!pos.empty())
	{
		string val = pos.back();
		pos.pop();

		char c1= val[0];
		char c2 = val[1];


	}


	cout << endl;
}