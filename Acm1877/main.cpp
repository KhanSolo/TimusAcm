#include <iostream>
using namespace std;

void main()
{
	int first, second;
	cin >> first;
	cin >> second;

	bool brk = false;
	for (int i = 0; i <= 9999; i++)
	{
		int num = i % 2 + 1; // номер замка

		if (1 == num )
		{
			if (first == i)
			{
				brk = true;
				break;
			}
		}
		else if (2 == num)
		{
			if (second == i)
			{
				brk = true;
				break;
			}
		}
	}

	cout << (brk ? "yes" : "no");
}