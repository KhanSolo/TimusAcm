#include <iostream>

using namespace std;

int main()
{
	int comps, cables;
	cin >> comps >> cables;
	
	int hours = 0, 
		copied = 1; // 2^hours

	// 1 ����
	while(
		copied < cables 
		&& 
		copied < comps
		)
	{
		hours++;
		copied = 1 << hours;
	}

	// 2 ����
	if (copied < comps)
	{
		hours += (comps - copied - 1) / cables + 1;
	}

	cout << hours;

	return 0;
}