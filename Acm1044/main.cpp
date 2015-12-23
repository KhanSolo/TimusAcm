#include <iostream>

using namespace std;

int inline sum_of_digits(int x)
{
	int res = 0;

	while (x > 0)
	{
		res += (x % 10);
		x = x / 10;
	}

	return res;
}

int main()
{
	int n;
	cin >> n;
	
	int k = 1; 
	int t = (n / 2);

	for (int i = 1; i <= t; i++, k *= 10);

	k--;

	int maxSum = t * 9;

	int s = 0;
	for (int i = 0; i <= maxSum; i++)
	{
		int c = 0;
		for (int j = 0; j<= k;j++)
		{
			if (i == sum_of_digits(j)) 
				c++;
		}
		s += c*c;
	}

	if (1 == (n % 2))	
		s *= 10;	
		
	cout << s;

	return 0;
}