#include <iostream>
#include <vector>
#include <string>

using namespace std;

const string NS = "No solution";

int main()
{
	int n, m;
	cin >> n >> m;
	
	if ((n*m) & 1 == 1)
	{
		cout << NS;
	
	}
	else
	{
		// доска
		vector<int> init_row(m, 0);
		vector<vector<int>> board(n, init_row);


	}
	return 0;
}