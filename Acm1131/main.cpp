#include <iostream>

using namespace std;

int main()
{
	int comps, cables;
	cin >> comps >> cables;
	
	int hours = 0, 
		copied = 1; // 2^hours

	// 1 фаза
	while(
		copied < cables 
		&& 
		copied < comps
		)
	{
		hours++;
		copied = 1 << hours;
	}

	// 2 фаза
	if (copied < comps)
	{
		hours += (comps - copied - 1) / cables + 1;
	}

	cout << hours;

	return 0;
}