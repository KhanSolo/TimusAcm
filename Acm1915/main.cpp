#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
const int MAXN = 1000000 + 10;
int a[2 * MAXN];
using namespace std;
int main()
{
	int n;
	scanf_s("%d", &n);
	int i = 1;
	while (n--)
	{
		int t;
		scanf_s("%d", &t);
		if (t > 0)
		{
			a[i++] = t;
		}
		else if (t == -1)
		{
			printf("%d\n", a[--i]);
		}
		else if (t == 0)
		{
			if (i - 1 <= n)
			{
				int num = min(i - 1, n);
				for (int j = 1; j <= num; ++j)
				{
					a[i] = a[i - num];
					++i;
				}
			}
		}
	}
	//system("pause");
	return 0;
}