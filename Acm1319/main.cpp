#include <iostream>
#include <vector>

using namespace std;

void inline print_reverse_row(const vector<int> &v) 
{
	int n = v.size();
	for (int i = 0; i < n; i++)
		cout << v[n - 1 - i] << " ";
	cout << endl;
}

int main()
{
	int n;
	cin >> n;

	if (1 == n)
	{
		cout << n;
		return 0;
	}

	if (2 == n)
	{
		cout << "2 1" << endl;
		cout << "4 3" << endl;
		return 0;
	}

	// n(n-1)/2 + 1

	vector<int>init(n, 0);
	vector<vector<int>> vv(n, init);
	
	// diagonals from 0 to n-1
	int val = 1;
	for (int i = 0; i < n; i++) // num of diag
	{
		for (int j = 0; j <= i; j++) // elem num in diag
		{
			// elem coords
			int x = i - j;
			int y =	/*i-*/	j;
						
			vv[y][x] = val;
			val++;
		}
	}



	// diagonals from n to 2*n-1

	int y = 0;
	for (int i = n; i < 2 * n - 1; i++)
	{
		int x = n - 1;
		do
		{
			y = i - x;
			vv[y][x] = val++;
			x--;
		} while (y != n - 1);
	}


	for (int i = 0; i < n; i++)
		print_reverse_row(vv[i]);

	//cout << "val : " << val << endl;

	return 0;
}