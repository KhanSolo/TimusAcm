#include <cstdio>

void main()
{
	int n, m;
	scanf_s("%d%d", &n, &m);
	if (n*m % 2 == 0)
		puts("[:=[first]");
	else
		puts("[second]=:]");
}