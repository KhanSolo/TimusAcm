#include <iostream>
using namespace std;
void main()
{
	/*
	�� 1 �� 4	���������	few
	�� 5 �� 9	�������	several
	�� 10 �� 19	�����	pack
	�� 20 �� 49	�����	lots
	�� 50 �� 99	����	horde
	�� 100 �� 249	���������	throng
	�� 250 �� 499	�������	swarm
	�� 500 �� 999	�������	zounds
	�� 1000	������	legion
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