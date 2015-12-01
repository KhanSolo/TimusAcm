#include <iostream>
using namespace std;

int sum(int a)
{
	int ed = a % 10;
	int sot = a / 100;
	int dec = a / 10 - sot * 10;
	return ed + sot + dec;
}

bool check(int num)
{
	int left, right;

	left = num / 1000;
	right = num % 1000;

//	cout << sum(left) << " " << sum(right);

	return sum(left) == sum(right);
}

void main()
{
	//_ASSERT(sum(123) == 6);

	int num;
	cin >> num;

	int prev;
	if (num == 0)
		prev = 999999;
	else
		prev = num - 1;

	int next;
	if (num == 999999)
		next = 0;
	else
		next = num + 1;

	bool result = check(prev) || check(next);

	cout << (result ? "Yes" : "No");
}