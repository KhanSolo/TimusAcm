#include <iostream>

using namespace std;

int main()
{
	int n; cin >> n;

	int sum = 0, max = 0;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >>	temp;
		sum += temp;
		if (temp > max) max = temp;
	}
	
	cout << sum + max;

	return 0;
}