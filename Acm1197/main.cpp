#include <iostream>
#include <queue>
#include <string>
using namespace std;

// ходы конём
void main()
{
	int board[8][8] = 
	{ 
		{ 2,3,4,4,4,4,3,2 },
		{ 3,4,6,6,6,6,4,3 },
		{ 4,6,8,8,8,8,6,4 },
		{ 4,6,8,8,8,8,6,4 },
		{ 4,6,8,8,8,8,6,4 },
		{ 4,6,8,8,8,8,6,4 },
		{ 3,4,6,6,6,6,4,3 },
		{ 2,3,4,4,4,4,3,2 },
	};

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
		string val = pos.front();
		pos.pop();

		char c1 = val[0] - 'a'; // 97
		char c2 = val[1] - '1'; // 49

		cout << board[c1][c2] << endl;
	}	
}