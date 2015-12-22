//#include <iostream>
#include <cstdio>
#include <vector>

/*
From the site FAQ on C/C++:

An example of how to use input/output is given above. 
C++ programmers may always choose between two input/output libraries: 
standard (scanf, printf) 
or stream (cin, cout) input/output. 

Stream input/output is easy to use, but it works much slower than standard input/output. 
This may even cause receiving the Time limit exceeded verdict. 
Therefore, if you see that a problem requires reading a lot of input data 
(for example, more than a megabyte) or a large output is expected, 
then you should better use standard input/output.

*/

using namespace std;

int min(int a, int b)
{
	if (a < b) return a;
	return b;
}

const int MAXN = 2097152;

int main()
{
	//cin.sync_with_stdio(false);
	
	vector<int> a(MAXN,0);

	int n; 	//cin >> n;
	scanf_s("%d", &n);

	int poin = 1; // next elem pointer
	while (n--)
	{
		int cur;  //cin >> cur;
		scanf_s("%d", &cur);
		if (cur > 0) // push
		{
			a[poin++] = cur;
			continue;
		}
		
		if (-1 == cur) // pop
		{
			//cout << a[--poin] << endl;
			auto r = a[--poin];
			printf_s("%d\n", r); 
			continue;
		}
			
		if (0 == cur) // copy
		{
			if (poin - 1 <= n)
			{
				int num = min(poin - 1, n);

				for (int j = 1; j <= num; ++j, poin++) 
					a[poin] = a[poin - num];						
			}
		}
	}

	return 0;
}