#include <iostream>
using namespace std;
void main()
{
	/*
	от 1 до 4	несколько	few
	от 5 до 9	немного	several
	от 10 до 19	отряд	pack
	от 20 до 49	толпа	lots
	от 50 до 99	орда	horde
	от 100 до 249	множество	throng
	от 250 до 499	сонмище	swarm
	от 500 до 999	полчище	zounds
	от 1000	легион	legion
	*/

	int a;
	cin >> a;

	if (a >= 1 && a < 5)
	{
		cout << "few";
		return;
	}

	if (a >= 5 && a < 10)
	{
		cout << "several";
		return;
	}

	if (a >= 10 && a < 20)
	{
		cout << "pack";
		return;
	}

	if (a >= 20 && a < 50)
	{
		cout << "lots";
		return;
	}

	if (a >= 50 && a < 100)
	{
		cout << "horde";
		return;
	}

	if (a >= 100 && a < 250)
	{
		cout << "throng";
		return;
	}

	if (a >= 250 && a < 500)
	{
		cout << "swarm";
		return;
	}

	if (a >= 500 && a < 1000)
	{
		cout << "zounds";
		return;
	}

	if (a >= 1000)
	{
		cout << "legion";
		return;
	}
	
}