/*
исходные данные	

4
1 3 6 10
2 5 9 13
4 8 12 15
7 11 14 16

результат
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16

*/

#include <iostream>
using namespace std;

void main()
{
	int n;
	cin >> n;

	int *ary = new int[n*n];

	for (int a = 0; a < n*n; a++)
	{
		cin >> ary[a];
	}


	int i = 0, j = 0;
	for (int a = 0; a < n; a++)
	{
		i = 0;
		do 
		{
			j = a - i;
			int val = ary[j*n + i];
			cout << val << " ";
			i++;
		} while (j != 0);
		
	}

	for (int a = n; a < 2*n-1; a++)
	{
		i = n - 1;
		do
		{
			j = a - i;
			int val = ary[i*n + j];
			cout << val << " ";
			i--;
		} while (j != n - 1);

	}

	delete[] ary;
}